

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PMPlayerController.generated.h"

/**
 * The PlayerController serves as the communication bridge between a human player and the character object.
 * It is responsible for receiving input from the player and translating it into actions for the character to perform.
 */
UCLASS()
class PROJECTMUTATIO_API APMPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	
	// Constructor of the PlayerController, wich is initialized when the game starts
	APMPlayerController();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void SetupInputComponent() override;

	void InitializeVariables();

	// Movement functions for the player character
	void MoveForward(float Value);
	void MoveRight(float Value);

	// Aim and vacuum functions for the player character
	void Aim();
	void StopAim();
	void VacuumOn();
	void VacuumOff();



    void UpdateAimRotation(float DeltaTime);


public:

	// The player character controlled by this PlayerController
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player Character")
	class APMPlayerCharacter* PlayerCharacter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player Character")
    class UCharacterMovementComponent* CharacterMovementComp;
	
	// The player character controlled by this PlayerController
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player Character")
	class UPMSoulVacuumComponent* SoulVacuumComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character States")
	bool bIsAiming = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character States")
	bool bVacuuming = false;
};
