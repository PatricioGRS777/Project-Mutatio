


#include "PMMonsterAIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Kismet/KismetMathLibrary.h"

APMMonsterAIController::APMMonsterAIController()
{

}

void APMMonsterAIController::BeginPlay()
{
    Super::BeginPlay();

    Idle();

}

void APMMonsterAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

void APMMonsterAIController::InitializeVariables()
{
    Super::InitializeVariables();
}

void APMMonsterAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

    PerceptionComp->OnTargetPerceptionUpdated.AddUniqueDynamic(this, &APMMonsterAIController::OnPerceptionUpdated);

    ReceiveMoveCompleted.AddUniqueDynamic(this, &APMMonsterAIController::OnMoveCompleted);

}

void APMMonsterAIController::OnPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
    Super::OnPerceptionUpdated(Actor, Stimulus);

}

void APMMonsterAIController::OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result)
{
    Super::OnMoveCompleted(RequestID, Result);

}

void APMMonsterAIController::Idle()
{
    Super::Idle();

}

void APMMonsterAIController::Chase()
{
    Super::Chase();
}

void APMMonsterAIController::Offensive()
{
    Super::Offensive();
}

void APMMonsterAIController::Attack()
{
    Super::Attack();

}

void APMMonsterAIController::BeginAttack()
{

}

void APMMonsterAIController::ReturnToStart()
{

}

void APMMonsterAIController::ContinueAttack()
{

}