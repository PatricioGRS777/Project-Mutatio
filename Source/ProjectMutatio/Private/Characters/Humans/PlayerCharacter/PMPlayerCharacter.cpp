


#include "PMPlayerCharacter.h"
#include "PlayerController/PMPlayerController.h"
#include "Components/PMSoulVacuumComponent.h"
#include "Perception/AISenseConfig_Hearing.h"
#include "Animation/AnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/WidgetComponent.h"
#include "Components/PMInteractionComponent.h"
#include "UI/Gameplay/PMCaptureBarWidget.h"

APMPlayerCharacter::APMPlayerCharacter()
{
    // Create the default subobject for the components
    SoulVacuumComp = CreateDefaultSubobject<UPMSoulVacuumComponent>(TEXT("Soul Vacuum Component"));
    SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm Component"));
    CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
    InteractionComp = CreateDefaultSubobject<UPMInteractionComponent>(TEXT("Interaction Component"));
    VacuumWidgetComp = CreateDefaultSubobject<UWidgetComponent>(TEXT("Widget Component"));

    SpringArmComp->SetupAttachment(GetRootComponent());
    CameraComp->SetupAttachment(SpringArmComp);
    VacuumWidgetComp->SetupAttachment(GetRootComponent());

    bUseControllerRotationYaw = false;
    bUseControllerRotationPitch = false;
    bUseControllerRotationRoll = false;

    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->MaxWalkSpeed = 350.0f;
    GetCharacterMovement()->MaxAcceleration = 1200.0f;
    GetCharacterMovement()->BrakingDecelerationWalking = 1400.0f;
    GetCharacterMovement()->GroundFriction = 8.0f;

    // This set the desire distance of the camera from the player character
    SpringArmComp->TargetArmLength = 800.0f;
    SpringArmComp->SetRelativeRotation(FRotator(-35.0f, -45.0f, 0.0f));
    SpringArmComp->bUsePawnControlRotation = false;
    SpringArmComp->bInheritYaw = false;
    SpringArmComp->bInheritPitch = false;
    SpringArmComp->bInheritRoll = false;

    VacuumWidgetComp->SetDrawSize(FVector2D(380.0f, 128.0f));
    VacuumWidgetComp->SetWidgetSpace(EWidgetSpace::Screen);

    VacuumWidgetComp->SetVisibility(false);

    // This establishes the Animation Blueprint for this character
    static ConstructorHelpers::FClassFinder<UAnimInstance>
        AnimBPClass(TEXT("/Game/Animations/Animation_Blueprints/Characters/Humans/Prototype_Character/ABP_PrototypeCharacter"));

    if (!AnimBPClass.Succeeded())
    {
        UE_LOG(LogTemp, Warning, TEXT("APMPlayerCharacter::APMPlayerCharacter() Animation Blueprint is null."));
        return;
    }

    GetMesh()->SetAnimInstanceClass(AnimBPClass.Class);

    static ConstructorHelpers::FClassFinder<UUserWidget>
        CaptureBarAsset(TEXT("/Game/UI/Gameplay/WBP_CaptureBar"));

    if (!CaptureBarAsset.Succeeded())
    {
        return;
    }

    CaptureBarWidgetClass = CaptureBarAsset.Class;

    VacuumWidgetComp->SetWidgetClass(CaptureBarWidgetClass);
}

void APMPlayerCharacter::BeginPlay()
{
    Super::BeginPlay();

    InitializeVariables();
}

void APMPlayerCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    UpdateCaptureBarPosition(DeltaTime);
}

void APMPlayerCharacter::InitializeVariables()
{
    PlayerController = Cast<APMPlayerController>(GetController());

    if (!PlayerController)
    {
        UE_LOG(LogTemp, Error, TEXT("APMPlayerCharacter::InitializeVariables() PlayerController is null."));
        return;
    }

}

void APMPlayerCharacter::SetCaptureBarVisibility(bool bHide)
{
    if (!VacuumWidgetComp)
    {
        UE_LOG(LogTemp, Error, TEXT("APMPlayerCharacter::HideCaptureBar() VacuumWidgetComp is null."));
        return;
    }

    VacuumWidgetComp->SetVisibility(bHide);
}

void APMPlayerCharacter::UpdateCaptureBarPosition(float DeltaTime)
{
    if (!PlayerController)
    {
        UE_LOG(LogTemp, Warning, TEXT("APMPlayerCharacter::UpdateCaptureBarPosition() PlayerController is null."));
        return;
    }

    FVector OffsetForward = GetActorForwardVector() * 100.0f;
    FVector OffsetUp = FVector(0.0f, 0.0f, 96.0f);
    FVector WorldLocation = GetActorLocation() + OffsetForward + OffsetUp;

    VacuumWidgetComp->SetWorldLocation(WorldLocation);
}

void APMPlayerCharacter::EmitAINoise(
    float Loudness,
    float MaxRange,
    FName NoiseTag)
{
    UAISense_Hearing::ReportNoiseEvent(
        GetWorld(),
        GetActorLocation(),
        Loudness,
        this,
        MaxRange,
        NoiseTag);
}

void APMPlayerCharacter::MoveForward(FVector Direction, float Value)
{
    AddMovementInput(Direction, Value);

    EmitAINoise(1.0f, 800.0f, FName("Footsteps"));
}

void APMPlayerCharacter::MoveRight(FVector Direction, float Value)
{
    AddMovementInput(Direction, Value);

    EmitAINoise(1.0f, 800.0f, FName("Footsteps"));
}

void APMPlayerCharacter::Interact(){
    this->InteractionComp->Interact();
}