


#include "PMPlayerCharacterAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"

UPMPlayerCharacterAnimInstance::UPMPlayerCharacterAnimInstance(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    UE_LOG(LogTemp, Warning, TEXT("UPMPlayerCharacterAnimInstance::UPMPlayerCharacterAnimInstance() AnimInstance initialized successfully"));

}

void UPMPlayerCharacterAnimInstance::NativeInitializeAnimation()
{
    Super::NativeInitializeAnimation();

}

void UPMPlayerCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
    Super::NativeUpdateAnimation(DeltaSeconds);

}