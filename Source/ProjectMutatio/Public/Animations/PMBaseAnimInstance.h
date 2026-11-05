

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PMBaseAnimInstance.generated.h"

/**
 * The AnimInstance manages and updates the animation of a skeletal mesh.
 * This is the basic animation class for all characters.
 */

UCLASS()
class PROJECTMUTATIO_API UPMBaseAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public: 

	UPMBaseAnimInstance(const FObjectInitializer& ObjectInitializer);

	virtual void NativeInitializeAnimation() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	virtual void InitializeVariables();

	virtual void UpdateAnimationProperties();

	UFUNCTION(BlueprintPure, Category = "Animation States")
	virtual bool IsMoving();

	UFUNCTION(BlueprintPure, Category = "Animation States")
	virtual bool IsFalling();

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
	class AActor* OwnerActor;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
	class ACharacter* OwnerCharacter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Animation States")
	float CharacterSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Animation States")
	float CharacterDirection;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Animation States")
	bool bIsMoving;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Animation States")
	bool bIsFalling;
	
};
