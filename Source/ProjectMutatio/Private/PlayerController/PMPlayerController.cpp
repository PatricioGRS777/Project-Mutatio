


#include "PMPlayerController.h"
#include "Characters/Humans/PlayerCharacter/PMPlayerCharacter.h"

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
    InputComponent->BindAxis("MoveBackward", this, &APMPlayerController::MoveBackward);
    InputComponent->BindAxis("MoveRight", this, &APMPlayerController::MoveRight);
    InputComponent->BindAxis("MoveLeft", this, &APMPlayerController::MoveLeft);


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
        UE_LOG(LogTemp, Error, TEXT("APMPlayerController::MoveForward() ControlledPawn is null."));
        return;
    }

    PlayerCharacter->MoveForward(Value);
}

void APMPlayerController::MoveBackward(float Value)
{
    if (!PlayerCharacter)
    {
        UE_LOG(LogTemp, Error, TEXT("APMPlayerController::MoveBackward() ControlledPawn is null."));
        return;
    }

    PlayerCharacter->MoveBackward(Value);
}

void APMPlayerController::MoveRight(float Value)
{
    if (!PlayerCharacter)
    {
        UE_LOG(LogTemp, Error, TEXT("APMPlayerController::MoveRight() ControlledPawn is null."));
        return;
    }

    PlayerCharacter->MoveRight(Value);
}

void APMPlayerController::MoveLeft(float Value)
{
    if (!PlayerCharacter)
    {
        UE_LOG(LogTemp, Error, TEXT("APMPlayerController::MoveLeft() ControlledPawn is null."));
        return;
    }

    PlayerCharacter->MoveLeft(Value);
}