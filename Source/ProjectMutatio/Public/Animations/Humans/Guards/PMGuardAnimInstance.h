

#pragma once

#include "CoreMinimal.h"
#include "Animations/Humans/PMHumanAnimInstance.h"
#include "PMGuardAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTMUTATIO_API UPMGuardAnimInstance : public UPMHumanAnimInstance
{
	GENERATED_BODY()

public:

	virtual void NativeInitializeAnimation() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	virtual void InitializeVariables() override;

	virtual void UpdateAnimationProperties() override;
	
};
