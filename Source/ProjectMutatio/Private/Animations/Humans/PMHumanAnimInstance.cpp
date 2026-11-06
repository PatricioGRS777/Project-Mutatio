


#include "PMHumanAnimInstance.h"

UPMHumanAnimInstance::UPMHumanAnimInstance(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    UE_LOG(LogTemp, Warning, TEXT("UPMHumanAnimInstance::UPMHumanAnimInstance() AnimInstance initialized Successfully."));
}

void UPMHumanAnimInstance::NativeInitializeAnimation()
{
    Super::NativeInitializeAnimation();

}

void UPMHumanAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
    Super::NativeUpdateAnimation(DeltaSeconds);
    
}