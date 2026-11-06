


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

    bIsMoving = IsMoving();
    bIsFalling = IsFalling();
}

bool UPMBaseAnimInstance::IsMoving()
{
    if (!OwnerCharacter)
    {
        UE_LOG(LogTemp, Error, TEXT("UPMBaseAnimInstance::IsMoving() OwnerCharacter is null."));
        return false;
    }

    FVector Velocity = OwnerCharacter->GetVelocity();

    CharacterSpeed = Velocity.Size2D();

    return CharacterSpeed > 0.0f;
}

bool UPMBaseAnimInstance::IsFalling()
{
    if (!OwnerCharacter)
    {
        UE_LOG(LogTemp, Error, TEXT("UPMBaseAnimInstance::IsFalling() OwnerCharacter is null."));
        return false;
    }

    if (!OwnerCharacter->GetCharacterMovement()->IsFalling())
    {
        return false;
    }

    return true;
}