


#include "PMBaseAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

UPMBaseAnimInstance::UPMBaseAnimInstance(const FObjectInitializer& ObjectInitializer)
{
    UE_LOG(LogTemp, Warning, TEXT("UPMBaseAnimInstance::UPMBaseAnimInstance() AnimInstance initialized successfully."));
}

void UPMBaseAnimInstance::NativeInitializeAnimation()
{
    Super::NativeInitializeAnimation();

    InitializeVariables();
}

void UPMBaseAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
    Super::NativeUpdateAnimation(DeltaSeconds);

    UpdateAnimationProperties();
}

void UPMBaseAnimInstance::InitializeVariables()
{
    OwnerActor = GetOwningActor();

    if (!OwnerActor)
    {
        UE_LOG(LogTemp, Error, TEXT("UPMBaseAnimInstance::InitializeVariables() OwnerActor is null."))
        return;
    }

    OwnerCharacter = Cast<ACharacter>(OwnerActor);

    if (!OwnerCharacter)
    {
        UE_LOG(LogTemp, Error, TEXT("UPMBaseAnimInstance::InitializeVariables() OwnerCharacter is null."))
        return;
    }
}

void UPMBaseAnimInstance::UpdateAnimationProperties()
{
    if (!OwnerActor)
    {
        UE_LOG(LogTemp, Error, TEXT("UPMBaseAnimInstance::UpdateAnimationProperties() OwnerActor is null."));
        return;
    }

    if (!OwnerCharacter)
    {
        UE_LOG(LogTemp, Error, TEXT("UPMBaseAnimInstance::UpdateAnimationProperties() OwnerCharacter is null."))
        return;
    }

    FVector Velocity = OwnerCharacter->GetVelocity();

    // Get character speed
    CharacterSpeed = Velocity.Size();

    // Transform the speed in the world to the character's local coordinates
    FVector LocalVelocity = OwnerCharacter->GetActorTransform().InverseTransformVectorNoScale(Velocity);

    // Take the direction angle
    float DirectionAngle = FMath::RadiansToDegrees(
        FMath::Atan2(LocalVelocity.Y, LocalVelocity.X));

    // Create a boundary between 0° and 180°
    CharacterDirection = FMath::Clamp(90.0f + DirectionAngle, 0.0f, 180.0f);

    bIsMoving = IsMoving();
    bIsFalling = IsFalling();

    UE_LOG(LogTemp, Warning, TEXT("UPMBaseAnimInstance::UpdateAnimationProperties() CharacterDirection: %f | Speed: %f"), CharacterDirection, CharacterSpeed);
}

bool UPMBaseAnimInstance::IsMoving()
{
    if (!OwnerCharacter)
    {
        UE_LOG(LogTemp, Error, TEXT("UPMBaseAnimInstance::IsMoving() OwnerCharacter is null."));
        return false;
    }

    return CharacterSpeed > 0.0f;
}

bool UPMBaseAnimInstance::IsFalling()
{
    if (!OwnerCharacter)
    {
        UE_LOG(LogTemp, Error, TEXT("UPMBaseAnimInstance::IsFalling() OwnerCharacter is null."));
        return false;
    }

    if (!OwnerCharacter->GetCharacterMovement())
    {
        UE_LOG(LogTemp, Error, TEXT("UPMBaseAnimInstance::IsFalling() CharacterMovementComponent is null."));
        return false;
    }

    if (!OwnerCharacter->GetCharacterMovement()->IsFalling())
    {
        return false;
    }

    return true;
}