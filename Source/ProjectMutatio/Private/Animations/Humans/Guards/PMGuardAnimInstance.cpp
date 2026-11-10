


#include "PMGuardAnimInstance.h"

void UPMGuardAnimInstance::NativeInitializeAnimation()
{
    Super::NativeInitializeAnimation();

    UE_LOG(LogTemp, Warning, TEXT("UPMGuardAnimInstance::NativeInitializeAnimation() AnimInstance initialized succesfully."));
}

void UPMGuardAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
    Super::NativeUpdateAnimation(DeltaSeconds);
}

void UPMGuardAnimInstance::InitializeVariables()
{
    Super::InitializeVariables();
}

void UPMGuardAnimInstance::UpdateAnimationProperties()
{
    Super::UpdateAnimationProperties();
}