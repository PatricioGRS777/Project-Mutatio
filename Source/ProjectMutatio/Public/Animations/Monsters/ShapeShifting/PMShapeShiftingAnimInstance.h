

#pragma once

#include "CoreMinimal.h"
#include "Animations/Monsters/PMMonsterAnimInstance.h"
#include "PMShapeShiftingAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTMUTATIO_API UPMShapeShiftingAnimInstance : public UPMMonsterAnimInstance
{
	GENERATED_BODY()

public:

	virtual void NativeInitializeAnimation() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	virtual void InitializeVariables() override;

	virtual void UpdateAnimationProperties();

	virtual bool IsMoving() override;

	virtual bool IsFalling() override;
};
