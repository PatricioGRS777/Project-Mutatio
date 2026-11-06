


#include "PMPlayerCharacter.h"
#include "Animation/AnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

APMPlayerCharacter::APMPlayerCharacter()
{
    // Create the default subobject for the components
    SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm Component"));
    CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));

    SpringArmComp->SetupAttachment(GetRootComponent());
    CameraComp->SetupAttachment(SpringArmComp);

    bUseControllerRotationYaw = false;
    bUseControllerRotationPitch = false;
    bUseControllerRotationRoll = false;

    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->MaxWalkSpeed = 350.0f;
    GetCharacterMovement()->MaxAcceleration = 1200.0f;
    GetCharacterMovement()->BrakingDecelerationWalking = 1400.0f;
    GetCharacterMovement()->GroundFriction = 8.0f;

    // This set the desire distance of the camera from the player character
    SpringArmComp->TargetArmLength = 1200.0f;
    SpringArmComp->SetRelativeRotation(FRotator(-35.0f, 0.0f, 0.0f));
    SpringArmComp->bUsePawnControlRotation = false;
    SpringArmComp->bInheritYaw = false;
    SpringArmComp->bInheritPitch = false;
    SpringArmComp->bInheritRoll = false;

    // This establishes the Animation Blueprint for this character
    static ConstructorHelpers::FClassFinder<UAnimInstance> 
        AnimBPClass(TEXT("/Game/Animations/Animation_Blueprints/Characters/Humans/Prototype_Character/ABP_PrototypeCharacter"));

    if (!AnimBPClass.Succeeded())
    {
        UE_LOG(LogTemp, Warning, TEXT("APMPlayerCharacter::APMPlayerCharacter() Animation Blueprint is null."));
        return;
    }

    GetMesh()->SetAnimInstanceClass(AnimBPClass.Class);

}

void APMPlayerCharacter::BeginPlay()
{
    Super::BeginPlay();

}

void APMPlayerCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

void APMPlayerCharacter::MoveForward(FVector Direction, float Value)
{
    AddMovementInput(Direction, Value);
}

void APMPlayerCharacter::MoveRight(FVector Direction, float Value)
{
    AddMovementInput(Direction, Value);
}