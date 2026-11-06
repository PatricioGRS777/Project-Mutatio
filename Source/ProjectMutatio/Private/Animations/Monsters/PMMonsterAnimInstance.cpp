


#include "PMMonsterAnimInstance.h"

UPMMonsterAnimInstance::UPMMonsterAnimInstance(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    UE_LOG(LogTemp, Warning, TEXT("UPMMonsterAnimInstance::UPMMonsterAnimInstance() AnimInstance initialized successfully."));
}

void UPMMonsterAnimInstance::NativeInitializeAnimation()
{
    Super::NativeInitializeAnimation();

}

void UPMMonsterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
    Super::NativeUpdateAnimation(DeltaSeconds);
    
}