

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

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UCameraComponent* CameraComp;
	
};
