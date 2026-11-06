

#pragma once

#include "CoreMinimal.h"
#include "Animations/PMBaseAnimInstance.h"
#include "PMHumanAnimInstance.generated.h"

/**
 * The AnimInstance class for all humans and their behaviors in animations.
 */

UCLASS()
class PROJECTMUTATIO_API UPMHumanAnimInstance : public UPMBaseAnimInstance
{
	GENERATED_BODY()

public:

	UPMHumanAnimInstance(const FObjectInitializer& ObjectInitializer);

	virtual void NativeInitializeAnimation() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
};
