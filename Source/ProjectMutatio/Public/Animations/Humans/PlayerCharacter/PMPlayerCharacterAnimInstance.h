

#pragma once

#include "CoreMinimal.h"
#include "Animations/Humans/PMHumanAnimInstance.h"
#include "PMPlayerCharacterAnimInstance.generated.h"

/**
 * The AnimInstance class for the player character what contains the functions and variables related to the animation state of the character.
 */

UCLASS()
class PROJECTMUTATIO_API UPMPlayerCharacterAnimInstance : public UPMHumanAnimInstance
{
	GENERATED_BODY()

public:

	UPMPlayerCharacterAnimInstance(const FObjectInitializer& ObjectInitializer);

	virtual void NativeInitializeAnimation() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

};
