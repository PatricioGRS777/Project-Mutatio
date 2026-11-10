


#include "PMShapeShiftingAnimInstance.h"

void UPMShapeShiftingAnimInstance::NativeInitializeAnimation()
{
    Super::NativeInitializeAnimation();
}

void UPMShapeShiftingAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
    Super::NativeUpdateAnimation(DeltaSeconds);
}

void UPMShapeShiftingAnimInstance::InitializeVariables()
{
    Super::InitializeVariables();
}

void UPMShapeShiftingAnimInstance::UpdateAnimationProperties()
{
    Super::UpdateAnimationProperties();
}

bool UPMShapeShiftingAnimInstance::IsMoving()
{
    return bIsMoving;
}

bool UPMShapeShiftingAnimInstance::IsFalling()
{
    return bIsFalling;
}