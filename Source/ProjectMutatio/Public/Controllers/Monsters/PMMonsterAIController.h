

#pragma once

#include "CoreMinimal.h"
#include "Controllers/PMBaseAIController.h"
#include "Navigation/PathFollowingComponent.h"
#include "PMMonsterAIController.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTMUTATIO_API APMMonsterAIController : public APMBaseAIController
{
	GENERATED_BODY()

public:
	
	APMMonsterAIController();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void InitializeVariables() override;

	virtual void OnPossess(APawn* InPawn) override;

	virtual void OnPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus) override;

	virtual void OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result) override;

	virtual void Idle() override;

	virtual void Chase() override;

	virtual void Offensive() override;

	virtual void Attack() override;

	virtual void BeginAttack();

	virtual void ReturnToStart();

	virtual void ContinueAttack();

public:


	
};
