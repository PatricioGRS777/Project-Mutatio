

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Navigation/PathFollowingComponent.h"
#include "Perception/AIPerceptionTypes.h"
#include "Controllers/PMAIState.h"
#include "PMBaseAIController.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTMUTATIO_API APMBaseAIController : public AAIController
{
	GENERATED_BODY()

public:

    APMBaseAIController();

    virtual void BeginPlay() override;

    virtual void Tick(float DeltaTime) override;

    virtual void InitializeVariables();

    virtual void OnPossess(APawn* InPawn) override;

    UFUNCTION()
    virtual void OnPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

    UFUNCTION()
    virtual void OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result);

    virtual void SetState(EAIState NewState);

    virtual void UpdateCharacterState(EAIState CurrentState);

    virtual void Idle();

    virtual void Patrol();

    virtual void Chase();

    virtual void Investigate();

    virtual void Offensive();
    
    virtual void Attack();

    virtual void Unconscious();


public:

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
    class UAIPerceptionComponent* PerceptionComp;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
    class UAISenseConfig_Sight* SightConfig;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
    class UAISenseConfig_Hearing* HearingConfig;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pawn Owner")
    class APawn* ControlledPawn;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player Character")
    class APMPlayerCharacter* PlayerCharacter;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI|States")
    EAIState AIState = EAIState::EAI_Idle;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI|Idle")
    FTimerHandle IdleTimer;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI|Patrol")
    FTimerHandle PatrolTimer;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI|Investigate")
    FTimerHandle InvestigateTimer;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI|Offensive")
    FTimerHandle OffensiveTimer;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI|Idle")
    float IdleDelay = 2.0f;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI|Patrol")
    float PatrolDelay = 4.0f;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI|Investigate")
    float InvestigateDelay = 10.0f;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI|Offensive")
    float OffensiveDelay = 2.0f;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI|Patrol")
    int32 CurrentPatrolIndex  = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	FVector PawnLocation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	FVector PlayerLocation;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
    FVector LastKnownLocation;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
    FVector LastNoiseLocation;

};
