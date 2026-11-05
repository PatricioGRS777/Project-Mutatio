

#pragma once

#include "CoreMinimal.h"
#include "Animations/PMBaseAnimInstance.h"
#include "PMMonsterAnimInstance.generated.h"

/**
 * AnimInstance class for all monster and their behaviors in animations
 */

UCLASS()
class PROJECTMUTATIO_API UPMMonsterAnimInstance : public UPMBaseAnimInstance
{
	GENERATED_BODY()

public:

	UPMMonsterAnimInstance(const FObjectInitializer& ObjectInitializer);

	virtual void NativeInitializeAnimation() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;	
};
