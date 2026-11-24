


#include "PMPlayerController.h"
#include "Characters/Humans/PlayerCharacter/PMPlayerCharacter.h"
#include "Components/PMSoulVacuumComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/SpringArmComponent.h"
#include "UI/PMMainMenuWidget.h"

APMPlayerController::APMPlayerController()
{
    UE_LOG(LogTemp, Warning, TEXT("APMPlayerController::APMPlayerController() PlayerController initialized successfully."));

    static ConstructorHelpers::FClassFinder<UUserWidget>
        MenuWidgetAsset(TEXT("/Game/UI/Main_Menu/BPW_MainMenu"));

    if (!MenuWidgetAsset.Succeeded())
    {
        UE_LOG(LogTemp, Error, TEXT("APMPlayerController::APMPlayerController() MenuWidgetAsset is null."));
        return; 
    }

    MenuWidgetClass = MenuWidgetAsset.Class;
}

void APMPlayerController::BeginPlay()
{
    Super::BeginPlay();

    InitializeVariables();

    UIManagement();
}

void APMPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    UE_LOG(LogTemp, Warning, TEXT("APMPlayerController::Tick() CaptureProgress: %s"), bApplyPulse? TEXT("TRUE") : TEXT("FALSE"));

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

    // Bind Actions
    // Aim and vacuum bind actions
    InputComponent->BindAction("Aim", IE_Pressed, this, &APMPlayerController::Aim);
    InputComponent->BindAction("StopAim", IE_Released, this, &APMPlayerController::StopAim);
    InputComponent->BindAction("VacuumOn", IE_Pressed, this, &APMPlayerController::VacuumOn);
    InputComponent->BindAction("VacuumOff", IE_Released, this, &APMPlayerController::VacuumOff);

    //Interact
    InputComponent->BindAction("Interact", IE_Pressed, this, &APMPlayerController::Interact);

    // Suction pulse
    InputComponent->BindAction("SuctionPulse", IE_Repeat, this, &APMPlayerController::PulsePressed);
    InputComponent->BindAction("SuctionPulse", IE_Released, this, &APMPlayerController::PulseReleased);

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

    SoulVacuumComp = Cast<UPMSoulVacuumComponent>(PlayerCharacter->GetComponentByClass(UPMSoulVacuumComponent::StaticClass()));
    if (!SoulVacuumComp)
    {
        UE_LOG(LogTemp, Error, TEXT("APMPlayerController::InitializeVariables() SoulVacuumComp is null."));
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

    PlayerCharacter->MoveRight(RightDirection, Value);
}

void APMPlayerController::UpdateAimRotation(float DeltaTime)
{
    if (!PlayerCharacter)
    {
        UE_LOG(LogTemp, Error, TEXT("APMPlayerController::UpdateAimRotation() PlayerCharacter is null."));
        return;
    }

    if (!SoulVacuumComp)
    {
        UE_LOG(LogTemp, Error, TEXT("APMPlayerController::UpdateAimRotation() SoulVacuumComp is null."));
        return;
    }

    SoulVacuumComp->UpdateAimRotation(DeltaTime);
}

void APMPlayerController::Aim()
{
    if (!PlayerCharacter)
    {
        UE_LOG(LogTemp, Error, TEXT("APMPlayerController::Aim() PlayerCharacter is null."));
        return;
    }

    CharacterMovementComp = PlayerCharacter->GetCharacterMovement();

    if (!CharacterMovementComp)
    {
        UE_LOG(LogTemp, Error, TEXT("APMPlayerController::Aim() CharacterMovementComp is null."));
        return;
    }

    bIsAiming = true;

    CharacterMovementComp->MaxWalkSpeed = 150.0f;

    CharacterMovementComp->bOrientRotationToMovement = false;

    bShowMouseCursor = true;

    FInputModeGameOnly InputMode;
    SetInputMode(InputMode);
}

void APMPlayerController::StopAim()
{
    if (!PlayerCharacter)
    {
        UE_LOG(LogTemp, Error, TEXT("APMPlayerController::StopAim() PlayerCharacter is null."));
        return;
    }

    CharacterMovementComp = PlayerCharacter->GetCharacterMovement();

    if (!CharacterMovementComp)
    {
        UE_LOG(LogTemp, Error, TEXT("APMPlayerController::StopAim() CharacterMovementComp is null."));
        return;
    }

    bIsAiming = false;

    CharacterMovementComp->MaxWalkSpeed = 350.0f;

    CharacterMovementComp->bOrientRotationToMovement = true;

    bShowMouseCursor = false;

    FInputModeGameOnly InputMode;

    SetInputMode(InputMode);
}

void APMPlayerController::VacuumOn()
{
    UE_LOG(LogTemp, Warning, TEXT("APMPlayerController::VacuumOn() Vacuum: On."));

    if (!PlayerCharacter)
    {
        UE_LOG(LogTemp, Error, TEXT("APMPlayerController::UpdateAimRotation() PlayerCharacter is null."));
        return;
    }

    if (!SoulVacuumComp)
    {
        UE_LOG(LogTemp, Error, TEXT("APMPlayerController::UpdateAimRotation() SoulVacuumComp is null."));
        return;
    }

    bVacuuming = true;
}

void APMPlayerController::VacuumOff()
{
    UE_LOG(LogTemp, Warning, TEXT("APMPlayerController::VacuumOff() Vacuum: Off."));
    
    bVacuuming = false;
}

void APMPlayerController::Interact(){
    if(!PlayerCharacter){
        UE_LOG(LogTemp, Error, TEXT("APMPlayerController::Interact() PlayerCharacter is null."));
        return;
    }
    PlayerCharacter->Interact();
}

void APMPlayerController::PulsePressed()
{
    if (!PlayerCharacter)
    {
        UE_LOG(LogTemp, Error, TEXT("APMPlayerController::SuctionPulse() PlayerCharacter is null."));
        return;
    }

    if (!SoulVacuumComp)
    {
        UE_LOG(LogTemp, Error, TEXT("APMPlayerController::SuctionPulse() SoulVacuumComp is null."));
        return;
    }

    bApplyPulse = true;

    SoulVacuumComp->ApplyPulse();

}

void APMPlayerController::PulseReleased()
{
    bApplyPulse = false;
}

void APMPlayerController::UIManagement()
{
    FString CurrentLevel = GetWorld()->GetMapName();

    CurrentLevel.RemoveFromStart(GetWorld()->StreamingLevelsPrefix);

    UUserWidget* NewWidget;

    if (CurrentLevel == TEXT("L_MainMenu"))
    {
        if (!MenuWidgetClass)
        {
            UE_LOG(LogTemp, Error, TEXT("APMPlayerController::UIManagement() MenuWidgetClass is null."));
            return;
        }

        NewWidget = CreateWidget<UUserWidget>(this, MenuWidgetClass);

        NewWidget->AddToViewport(99);
    }
}