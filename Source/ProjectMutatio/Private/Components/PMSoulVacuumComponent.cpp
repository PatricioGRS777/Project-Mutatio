


#include "PMSoulVacuumComponent.h"
#include "Characters/Humans/PlayerCharacter/PMPlayerCharacter.h"
#include "Characters/Monsters/ShapeShifting/PMShapeShiftingCharacter.h"
#include "PlayerController/PMPlayerController.h"
#include "Controllers/Monsters/ShapeShifting/PMShapeShiftingAIController.h"
#include "Kismet/KismetMathLibrary.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values for this component's properties
UPMSoulVacuumComponent::UPMSoulVacuumComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	UE_LOG(LogTemp, Warning, TEXT("UPMSoulVacuumComponent::UPMSoulVacuumComponent() Actor component initialized successfully."));
}


// Called when the game starts
void UPMSoulVacuumComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	InitializeVariables();

}


// Called every frame
void UPMSoulVacuumComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	UpdateSoulVacuum(DeltaTime);

}

void UPMSoulVacuumComponent::InitializeVariables()
{
	AActor* OwningActor = GetOwner();

	if (!OwningActor)
	{
		UE_LOG(LogTemp, Error, TEXT("UPMSoulVacuumComponent::InitializeVariables() OwningActor is null."));
		return;
	}

	PlayerCharacter = Cast<APMPlayerCharacter>(OwningActor);

	if (!PlayerCharacter)
	{
		UE_LOG(LogTemp, Error, TEXT("UPMSoulVacuumComponent::InitializeVariables() PlayerCharacter is null."));
		return;
	}
	
	PlayerController = Cast<APMPlayerController>(PlayerCharacter->GetController());

	if (!PlayerController)
	{
		UE_LOG(LogTemp, Error, TEXT("UPMSoulVacuumComponent::InitializeVariables() PlayerController is null."));
		return;
	}
}

void UPMSoulVacuumComponent::UpdateSoulVacuum(float DeltaTime)
{
	if (!PlayerController)
	{
		UE_LOG(LogTemp, Error, TEXT("UPMSoulVacuumComponent::TickComponent() PlayerController is null."));
		return;
	}

	if (!PlayerCharacter)
	{
		UE_LOG(LogTemp, Error, TEXT("UPMSoulVacuumComponent::TickComponent() PlayerCharacter is null."));
		return;
	}

	if (PlayerController->bIsAiming)
	{
		UpdateAimRotation(DeltaTime);
	}

	if (PlayerController->bVacuuming)
	{
		UpdateVacuumTarget(DeltaTime);
	}
	else
	{
		CaptureProgress = 0.0f;
	}

	if (!ShiftingCharacter)
	{
		UE_LOG(LogTemp, Error, TEXT("UPMSoulVacuumComponent::UpdateSoulVacuum() ShiftingCharacter is null."));
		return;
	}

	if (!bHasOriginalTransform)
	{
		return;
	}

	if (PlayerController->bVacuuming)
	{
		CaptureProgress += VacuumProgressRate * DeltaTime;
	}
	else
	{
		CaptureProgress -= DecayRate * DeltaTime;

	    SetPlayerMovementEnabled(true);
	}

	CaptureProgress = FMath::Clamp(
		CaptureProgress,
		0.0f,
		MaxCaptureProgress);

	UE_LOG(LogTemp, Warning, TEXT("UPMSoulVacuumComponent::InitializeVariables() CaptureProgress: %f"), CaptureProgress);

	UpdateTargetTransform(DeltaTime);

	if (CaptureProgress >= 100.0F)
	{
		ShiftingCharacter->Destroy();

		SetPlayerMovementEnabled(true);

		ShiftingCharacter = nullptr;
	}
	else if (CaptureProgress <= 0.0f)
	{
		const float DistanceToOriginal = FVector::Dist(
			ShiftingCharacter->GetActorLocation(),
			OriginalMonsterLocation);

		if (DistanceToOriginal <= 2.0f)
		{
			ShiftingCharacter->SetActorLocation(
				OriginalMonsterLocation,
				false);

			ShiftingCharacter->SetActorScale3D(
				OriginalMonsterScale);

			SetPlayerMovementEnabled(true);

			ShiftingCharacter = nullptr;

			bHasOriginalTransform = false;

			if (!ShiftingAIController)
			{
				UE_LOG(LogTemp, Error, TEXT("UPMSoulVacuumComponent::UpdateSoulVacuum() ShiftingAIController is null."));
				return;
			}

			ShiftingAIController->AIState = EAIState::EAI_Chase;
		}
	}
}

void UPMSoulVacuumComponent::UpdateAimRotation(float DeltaTime)
{
	if (!PlayerCharacter)
	{
		UE_LOG(LogTemp, Error, TEXT("UPMSoulVacuumComponent::UpdateAimRotation() PlayerCharacter is null."));
		return;
	}

	if (!PlayerController)
	{
		UE_LOG(LogTemp, Error, TEXT("UPMSoulVacuumComponent::UpdateAimRotation() PlayerController is null."));
		return;
	}

	FHitResult HitResult;

	const bool bHit = PlayerController->GetHitResultUnderCursorByChannel(
		UEngineTypes::ConvertToTraceType(ECC_Visibility),
		true,
		HitResult);

	if (!bHit)
	{
		return;
	}

	const FVector CharacterLocation = PlayerCharacter->GetActorLocation();
	const FVector TargetLocation = HitResult.Location;

	const FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(
		CharacterLocation,
		TargetLocation);

	const FRotator CurrentRotation = PlayerCharacter->GetActorRotation();
	const FRotator TargetRotation (0.0f, LookAtRotation.Yaw, 0.0f);

	const FRotator NewRotation = FMath::RInterpConstantTo(
		CurrentRotation,
		TargetRotation,
		DeltaTime,
		AimRotationSpeed);

	PlayerCharacter->SetActorRotation(NewRotation);
}

void UPMSoulVacuumComponent::UpdateVacuumTarget(float DeltaTime)
{
	if (!PlayerCharacter)
	{
		UE_LOG(LogTemp, Error, TEXT("UPMSoulVacuumComponent::VacuumOn() PlayerCharacter is null."));
		return;
	}

	if (!PlayerCharacter->GetMesh())
	{
		UE_LOG(LogTemp, Error, TEXT("UPMSoulVacuumComponent::VacuumOn() SkeletalMesh is not valid"));
		return;
	}

	PlayerCharacter->EmitAINoise(1.0f, 800.0f, FName("Vacuum"));

	const FVector StartLocation = PlayerCharacter->GetMesh()->GetSocketLocation(TEXT("spine_03"));

	const FVector EndLocation = StartLocation + (PlayerCharacter->GetActorForwardVector() * VacuumRange);

	FHitResult HitResult;

	FCollisionQueryParams QueryParams;

	QueryParams.AddIgnoredActor(PlayerCharacter);

	const bool bHit = GetWorld()->SweepSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		FQuat::Identity,
		ECC_Pawn,
		FCollisionShape::MakeSphere(50.0f),
		QueryParams
	);

	if (!bHit)
	{
		return;
	}

	// DrawDebugCylinder(
	// 	GetWorld(),
	// 	StartLocation,
	// 	EndLocation,
	// 	32.0f,
	// 	32.0f,
	// 	FColor::Green,
	// 	false,
	// 	2.0f);

	APMShapeShiftingCharacter* DetectedCharacter = Cast<APMShapeShiftingCharacter>(HitResult.Actor);

	if (!DetectedCharacter)
	{
		UE_LOG(LogTemp, Error, TEXT("UPMSoulVacuumComponent::UpdateVacuumTarget() DetectedCharacter is null."));
		return;
	}

	if (DetectedCharacter == ShiftingCharacter)
	{
		return;
	}

	if (ShiftingCharacter && bHasOriginalTransform)
	{
		return;
	}

	ShiftingCharacter = DetectedCharacter;

	if (!ShiftingCharacter)
	{
		UE_LOG(LogTemp, Error, TEXT("UPMSoulVacuumComponent::UpdateVacuumTarget() ShiftingCharacter is null."));
		return;
	}

	OriginalMonsterLocation = ShiftingCharacter->GetActorLocation();

	OriginalMonsterScale = ShiftingCharacter->GetActorScale3D();

	bHasOriginalTransform = true;

	ShiftingAIController = Cast<APMShapeShiftingAIController>(ShiftingCharacter->GetController());
	
	if (!ShiftingAIController)
	{
		UE_LOG(LogTemp, Error, TEXT("UPMSoulVacuumComponent::UpdateVacuumTarget() ShiftingAIController is null."));
		return;
	}

	ShiftingAIController->StopMovement();

	if(!ShiftingCharacter->GetCharacterMovement())
	{
		UE_LOG(LogTemp, Error, TEXT("UPMSoulVacuumComponent::UpdateVacuumTarget() CharacterMovementComponent is null."));
		return;
	}

	ShiftingCharacter->GetCharacterMovement()->StopMovementImmediately();

	SetPlayerMovementEnabled(false);
}

void UPMSoulVacuumComponent::ApplyPulse()
{
	if (!PlayerController || !PlayerController->bVacuuming)
	{
		return;
	}

	if (!ShiftingCharacter || !bHasOriginalTransform)
	{
		return;
	}

	CaptureProgress = FMath::Clamp(
		CaptureProgress + PulsePower,
		0.0f,
		MaxCaptureProgress);
}

void UPMSoulVacuumComponent::UpdateTargetTransform(float DeltaTime)
{
	if (!ShiftingCharacter || !PlayerCharacter ||
		!PlayerController || !bHasOriginalTransform || 
		!ShiftingAIController)
	{
		return;
	}

	const float ProgressAlpha = FMath::Clamp(
		CaptureProgress / MaxCaptureProgress,
		0.0f,
		1.0f);

	FVector DesiredLocation = OriginalMonsterLocation;

	FVector CurrentScale = ShiftingCharacter->GetActorScale3D();

	FVector DesiredScale = OriginalMonsterScale;

	if (PlayerController->bVacuuming)
	{
		const FVector VacuumLocation = PlayerCharacter->GetMesh()->GetSocketLocation(TEXT("spine_03"));

		const FVector VacuumTarget = 
			VacuumLocation +
			(PlayerCharacter->GetActorForwardVector() * SuctionDistance);

		DesiredLocation = FMath::Lerp(
			OriginalMonsterLocation,
			VacuumTarget,
			ProgressAlpha);
			
		CurrentScale = ShiftingCharacter->GetActorScale3D();

		const FVector TargetScale = OriginalMonsterScale * MinMonsterScale;

		DesiredScale = FMath::Lerp(
			OriginalMonsterScale,
			TargetScale,
			ProgressAlpha);
	}

	const FVector NewLocation = FMath::VInterpConstantTo(
		ShiftingCharacter->GetActorLocation(),
		DesiredLocation,
		DeltaTime,
		MonsterPullSpeed);

	ShiftingCharacter->SetActorLocation(NewLocation);

	const FVector NewScale = FMath::VInterpTo(
		CurrentScale,
		DesiredScale,
		DeltaTime,
		ScaleInterpSpeed);

	ShiftingCharacter->SetActorScale3D(NewScale);
}

void UPMSoulVacuumComponent::SetPlayerMovementEnabled(bool bEnabled)
{
	if (!PlayerCharacter)
	{
		UE_LOG(LogTemp, Error, TEXT("UMPSoulVacuumComponent::SetPlayerMovementEnabled() PlayerCharacter is null."));
		return;
	}

	UCharacterMovementComponent* MovementComponent = PlayerCharacter->GetCharacterMovement();

	if (!MovementComponent)
	{
		UE_LOG(LogTemp, Error, TEXT("UMPSoulVacuumComponent::SetPlayerMovementEnabled() MovementComponent is null."));
	}

	MovementComponent->SetMovementMode(
		bEnabled? MOVE_Walking : MOVE_None);
}