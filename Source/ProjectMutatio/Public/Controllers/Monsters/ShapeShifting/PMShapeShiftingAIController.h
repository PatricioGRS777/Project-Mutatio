

#pragma once

#include "CoreMinimal.h"
#include "Controllers/Monsters/PMMonsterAIController.h"
#include "PMShapeShiftingAIController.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTMUTATIO_API APMShapeShiftingAIController : public APMMonsterAIController
{
	GENERATED_BODY()

public:

	APMShapeShiftingAIController();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void InitializeVariables() override;

	virtual void OnPossess(APawn* InPawn) override;

	virtual void OnPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus) override;

	virtual void OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result) override;

	virtual void Idle() override;

	virtual void Disguise(); 

	virtual void Chase() override;

	virtual void Offensive() override;

	virtual void Attack() override;

	virtual void BeginAttack() override;

	virtual void ReturnToStart() override;

	virtual void ContinueAttack() override;

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
	class APMShapeShiftingCharacter* ShiftingCharacter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI|Attack")
	FVector AttackStartLocation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI|Attack")
	FTimerHandle AttackPhaseTimer;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI|Attack")
	float AttackPreparationTime = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI|Attack")
	float AttackCooldown = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI|Attack")
	float AttackDuration = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI|Attack")
	float AttackSpeed = 3200.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI|Attack")
	int32 AttacksRemaining;
};
