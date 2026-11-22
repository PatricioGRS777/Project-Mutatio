

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Controllers/PMAIState.h"
#include "PMSoulVacuumComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTMUTATIO_API UPMSoulVacuumComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPMSoulVacuumComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void InitializeVariables();

	void UpdateSoulVacuum(float DeltaTime);

	void UpdateAimRotation(float DeltaTime);

	void UpdateVacuumTarget(float DeltaTime);

	void ApplyPulse();

	void UpdateTargetTransform(float DeltaTime);

	void SetPlayerMovementEnabled(bool bEnabled);

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player Character")
	class APMPlayerCharacter* PlayerCharacter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	class APMShapeShiftingCharacter* ShiftingCharacter;

	class APMShapeShiftingAIController* ShiftingAIController;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player Character")
	class APMPlayerController* PlayerController;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player Character")
	float AimRotationSpeed = 279.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Character")
	float VacuumRange = 500.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player Character")
	class USkeletalMeshSocket* BoneSocket;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player Character")
	float CaptureProgress = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player Character")
	float MaxCaptureProgress = 100.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player Character")
	float SuctionPower = 18.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player Character")
	float DecayRate = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Vacuum")
	float PulsePower = 8.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Vacuum")
	float MonsterPullSpeed = 500.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Shape Shifting Character")
	FVector OriginalMonsterLocation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Shape Shifting Character")
	FVector OriginalMonsterScale;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Shape Shifting Character")
	bool bHasOriginalTransform = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Shape Shifting Character")
	float VacuumProgressRate = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Vacuum")
	float SuctionDistance = 120.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Vacuum")
	float MinMonsterScale = 0.5f;

	UPROPERTY(EditAnywhere, Category = "Soul Vacuum|Transformation")
	float ScaleInterpSpeed = 8.0f;

};
