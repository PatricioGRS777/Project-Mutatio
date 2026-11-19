


#include "PMGuardAIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Characters/Humans/Guards/PMGuardCharacter.h"
#include "Characters/Humans/PlayerCharacter/PMPlayerCharacter.h"

APMGuardAIController::APMGuardAIController()
{

}

void APMGuardAIController::BeginPlay()
{
    Super::BeginPlay();

    InitializeVariables();

}

void APMGuardAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void APMGuardAIController::InitializeVariables()
{
    Super::InitializeVariables();

}

void APMGuardAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

}

void APMGuardAIController::OnPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
    Super::OnPerceptionUpdated(Actor, Stimulus);

}

void APMGuardAIController::OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result)
{
    Super::OnMoveCompleted(RequestID, Result);

}

void APMGuardAIController::Idle()
{
    Super::Idle();

}

void APMGuardAIController::Patrol()
{
    Super::Patrol();

}

void APMGuardAIController::Investigate()
{
    Super::Investigate();

}

void APMGuardAIController::Chase()
{
    Super::Chase();

}

void APMGuardAIController::Offensive()
{
    Super::Offensive();

}

void APMGuardAIController::Attack()
{
    Super::Attack();

}