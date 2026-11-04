


#include "PMPlayerCharacter.h"
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

    SpringArmComp->SetRelativeRotation(FRotator(-35.0f, 0.0f, 0.0f));

    // This set the desire distance of the camera from the player character
    SpringArmComp->TargetArmLength = 1200.0f;

    GetCharacterMovement()->MaxWalkSpeed = 350.0f;
    GetCharacterMovement()->MaxAcceleration = 1200.0f;
    GetCharacterMovement()->BrakingDecelerationWalking = 1400.0f;
    GetCharacterMovement()->GroundFriction = 8.0f;

}

void APMPlayerCharacter::BeginPlay()
{
    Super::BeginPlay();

}

void APMPlayerCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

void APMPlayerCharacter::MoveForward(float Value)
{
    AddMovementInput(GetActorForwardVector(), Value);
}

void APMPlayerCharacter::MoveBackward(float Value)
{
    AddMovementInput(GetActorForwardVector(), -Value);
}

void APMPlayerCharacter::MoveRight(float Value)
{
    AddMovementInput(GetActorRightVector(), Value);
}

void APMPlayerCharacter::MoveLeft(float Value)
{
    AddMovementInput(GetActorRightVector(), -Value);
}