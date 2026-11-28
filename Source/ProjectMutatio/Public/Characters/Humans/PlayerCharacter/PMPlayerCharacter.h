

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

	void InitializeVariables();

	void SetCaptureBarVisibility(bool bHide);

	void UpdateCaptureBarPosition(float DeltaTime);

	UFUNCTION()
	void EmitAINoise(
		float Loudness,
		float MaxRange,
		FName NoiseTag);

	// Movement functions for the player character
	void MoveForward(FVector Direction, float Value);
	void MoveRight(FVector Direction, float Value);
	
	// Interaction functions
	void Interact();

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player Controller")
	class APMPlayerController* PlayerController;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UPMSoulVacuumComponent* SoulVacuumComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UCameraComponent* CameraComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UPMInteractionComponent* InteractionComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI|Widget Component")
	class UWidgetComponent* VacuumWidgetComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI")
	TSubclassOf<class UPMCaptureBarWidget> CaptureBarWidgetClass;

	
};
