


#include "PMPlayerController.h"
#include "Characters/Humans/PlayerCharacter/PMPlayerCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/SpringArmComponent.h"

APMPlayerController::APMPlayerController()
{
    UE_LOG(LogTemp, Warning, TEXT("APMPlayerController::APMPlayerController() PlayerController initialized successfully."));
}

void APMPlayerController::BeginPlay()
{
    Super::BeginPlay();

    InitializeVariables();
}

void APMPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

void APMPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    if (!InputComponent)
    {
        UE_LOG(LogTemp, Error, TEXT("APMPlayerController::SetupInputComponent() InputComponent is null."));
        return;
    }

    InputComponent->BindAxis("MoveForward", this, &APMPlayerController::MoveForward);
    InputComponent->BindAxis("MoveRight", this, &APMPlayerController::MoveRight);
}

void APMPlayerController::InitializeVariables()
{
    APawn* ControlledPawn = GetPawn();

    if (!ControlledPawn)
    {
        UE_LOG(LogTemp, Error, TEXT("APMPlayerController::InitializeVariables() ControlledPawn is null."));
        return;
    }

    PlayerCharacter = Cast<APMPlayerCharacter>(ControlledPawn);

    if (!PlayerCharacter)
    {
        UE_LOG(LogTemp, Error, TEXT("APMPlayerController::InitializeVariables() PlayerCharacter is null."));
        return;
    }
}

void APMPlayerController::MoveForward(float Value)
{
    if (!PlayerCharacter)
    {
        UE_LOG(LogTemp, Error, TEXT("APMPlayerController::MoveForward() PlayerCharacter is null."));
        return;
    }

    FRotator SpringArmRot = PlayerCharacter->SpringArmComp->GetComponentRotation();
    FRotator CharacterRot = PlayerCharacter->GetActorRotation();

    const FRotator YawRotation(0.0f, UKismetMathLibrary::NormalizedDeltaRotator(SpringArmRot, CharacterRot).Yaw, 0.0f);

    const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

    PlayerCharacter->MoveForward(ForwardDirection, Value);
}

void APMPlayerController::MoveRight(float Value)
{
    if (!PlayerCharacter)
    {
        UE_LOG(LogTemp, Warning, TEXT("APMPlayerController::MoveLeft() PlayerCharacter is null."))
        return;
    }

    FRotator SpringArmRot = PlayerCharacter->SpringArmComp->GetComponentRotation();
    FRotator CharacterRot = PlayerCharacter->GetActorRotation();

    const FRotator YawRotation(0.0f, UKismetMathLibrary::NormalizedDeltaRotator(SpringArmRot, CharacterRot).Yaw, 0.0f);

    const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

    PlayerCharacter->MoveForward(RightDirection, Value);
}
