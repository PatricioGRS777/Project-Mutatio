


#include "PMSoulVacuumComponent.h"
#include "Characters/Humans/PlayerCharacter/PMPlayerCharacter.h"
#include "PlayerController/PMPlayerController.h"
#include "Kismet/KismetMathLibrary.h"
#include "DrawDebugHelpers.h"

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

	if (PlayerController && PlayerController->bIsAiming)
	{
		UpdateAimRotation(DeltaTime);

		if (PlayerController->bIsAiming && PlayerController->bVacuuming)
		{
			VacuumOn();
		}
	}
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

void UPMSoulVacuumComponent::VacuumOn()
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

	DrawDebugCylinder(
		GetWorld(),
		StartLocation,
		EndLocation,
		32.0f,
		32.0f,
		FColor::Green,
		false,
		2.0f);
}

void UPMSoulVacuumComponent::VacuumOff()
{

}