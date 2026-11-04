

#pragma once

#include "CoreMinimal.h"
#include "Characters/Humans/PMHumanCharacter.h"
#include "PMPlayerCharacter.generated.h"

/**
 * 
 */

UCLASS()
class PROJECTMUTATIO_API APMPlayerCharacter : public APMHumanCharacter
{
	GENERATED_BODY()

public:

	// Constructor of the player character class
	APMPlayerCharacter();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	// Movement functions for the player character
	void MoveForward(float Value);
	void MoveBackward(float Value);
	void MoveRight(float Value);
	void MoveLeft(float Value);

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UCameraComponent* CameraComp;
	
};
