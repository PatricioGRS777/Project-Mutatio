

#pragma once

#include "CoreMinimal.h"
#include "Controllers/Humans/PMHumanAIController.h"
#include "Controllers/PMAIState.h"
#include "PMGuardAIController.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTMUTATIO_API APMGuardAIController : public APMHumanAIController
{
	GENERATED_BODY()

public:

	APMGuardAIController();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void InitializeVariables() override;

	virtual void OnPossess(APawn* InPawn) override;

	virtual void OnPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus) override;

	virtual void OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result) override;

	virtual void Idle() override;

	virtual void Patrol() override;

	virtual void Investigate() override;

	virtual void Chase() override;

	virtual void Offensive() override;

	virtual void Attack() override;

public:

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pawn Owner")
    class APMGuardCharacter* GuardCharacter;
	
};
