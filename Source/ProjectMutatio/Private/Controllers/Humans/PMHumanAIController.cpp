


#include "PMHumanAIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Characters/Humans/Guards/PMGuardCharacter.h"
#include "Characters/Humans/PlayerCharacter/PMPlayerCharacter.h"
#include "Controllers/PMAIState.h"

APMHumanAIController::APMHumanAIController()
{

}

void APMHumanAIController::BeginPlay() 
{
    Super::BeginPlay();

    InitializeVariables();

    Idle();
}

void APMHumanAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    UpdateCharacterState(AIState);
}

void APMHumanAIController::InitializeVariables()
{
    Super::InitializeVariables();

    HumanCharacter = Cast<APMHumanCharacter>(ControlledPawn);

    if (!HumanCharacter)
    {
        UE_LOG(LogTemp, Error, TEXT("APMHumanAIController::InitializeVariables() HumanCharacter is null."));
        return;
    }
}

void APMHumanAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

}

void APMHumanAIController::OnPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
    Super::OnPerceptionUpdated(Actor, Stimulus);

    APMPlayerCharacter* DetectedPlayer = Cast<APMPlayerCharacter>(Actor);

    if (!DetectedPlayer)
    {
        UE_LOG(LogTemp, Error, TEXT("APMHumanAIController::OnPerceptionUpdated() DetectedPlayer is null."));
        return;
    }

    if (Stimulus.WasSuccessfullySensed())
    {
        PlayerCharacter = DetectedPlayer;

        LastKnownLocation = PlayerCharacter->GetActorLocation();

        Chase();
    }
    else
    {
        LastKnownLocation = Stimulus.StimulusLocation;

        PlayerCharacter = nullptr;

        Investigate();
    }
}

void APMHumanAIController::OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result)
{
    Super::OnMoveCompleted(RequestID, Result);
    
    switch (Result)
    {
        case EPathFollowingResult::Success :
            UE_LOG(LogTemp, Warning, TEXT("APMHumanAIController::OnMoveCompleted() Character reach destiny."));

            if (AIState == EAIState::EAI_Patrol)
            {
                CurrentPatrolIndex = (CurrentPatrolIndex + 1) % HumanCharacter->PatrolPoints.Num();
                
                GetWorldTimerManager().SetTimer(
                    PatrolTimer,
                    this,
                    &APMHumanAIController::Patrol,
                    PatrolDelay,
                    false);
            }

            else if (AIState == EAIState::EAI_Investigate)
            {
                GetWorldTimerManager().SetTimer(
                    InvestigateTimer,
                    this,
                    &APMHumanAIController::Patrol,
                    InvestigateDelay,
                    false);
            }

            else if (AIState == EAIState::EAI_Chase)
            {
                Offensive();
            }
            break;

        case EPathFollowingResult::Blocked :
            UE_LOG(LogTemp, Warning, TEXT("APMHumanAIController::OnMoveCompleted() The path is blocked."));

            break;

        case EPathFollowingResult::Aborted :
            UE_LOG(LogTemp, Warning, TEXT("APMHumanAIController::OnMoveCompleted() Aborted."));

            break;
    }
}

void APMHumanAIController::SetState(EAIState NewState)
{
    Super::SetState(NewState);

}

void APMHumanAIController::UpdateCharacterState(EAIState CurrentState)
{
    Super::UpdateCharacterState(CurrentState);

}

void APMHumanAIController::Idle()
{
    SetState(EAIState::EAI_Idle);

    UE_LOG(LogTemp, Warning, TEXT("APMHumanAIController::Idle() Idle."));

    GetWorldTimerManager().SetTimer(
        IdleTimer,
        this,
        &APMHumanAIController::Patrol,
        IdleDelay,
        false);
}

void APMHumanAIController::Patrol()
{
    Super::Patrol();

    if (HumanCharacter->PatrolPoints.Num() == 0)
    {
        UE_LOG(LogTemp, Error, TEXT("APMHumanAIController::Patrol() PatrolPoints is empty. Make sure to fill the array with actors."));
        return;
    }

    if (!HumanCharacter->PatrolPoints.IsValidIndex(CurrentPatrolIndex))
    {
        CurrentPatrolIndex = 0;
    }

    AActor* CurrentActor = HumanCharacter->PatrolPoints[CurrentPatrolIndex];

    if (!CurrentActor)
    {
        UE_LOG(LogTemp, Error, TEXT("APMHumanAIController::Patrol() CurrentActor is null"));
        return;
    }

    SetState(EAIState::EAI_Patrol);

    UE_LOG(LogTemp, Warning, TEXT("APMHumanAIController::Patrol() Moving the character to the patrol point: %i"), CurrentPatrolIndex);

    MoveToLocation(CurrentActor->GetActorLocation(), 25.0f);

}

void APMHumanAIController::Investigate()
{
    Super::Investigate();

    SetState(EAIState::EAI_Investigate);

    UE_LOG(LogTemp, Warning, TEXT("APMHumanAIController::Investigate() Investigating."));

    MoveToLocation(LastKnownLocation, 25.0f);
}

void APMHumanAIController::Chase()
{
    Super::Chase();

    if (!PlayerCharacter)
    {
        UE_LOG(LogTemp, Warning, TEXT("APMHumanAIController::Chase() PlayerCharacter is null."));
        return;
    }

    SetState(EAIState::EAI_Chase);

    UE_LOG(LogTemp, Warning, TEXT("APMHumanAIController::Chase() Chasing the player."));

    GetWorldTimerManager().ClearTimer(IdleTimer);
    GetWorldTimerManager().ClearTimer(PatrolTimer);
    GetWorldTimerManager().ClearTimer(InvestigateTimer);

    MoveToActor(PlayerCharacter, 100.0f);
}

void APMHumanAIController::Offensive()
{
    Super::Offensive();

    SetState(EAIState::EAI_Offensive);

    UE_LOG(LogTemp, Warning, TEXT("APMHumanAIController::Attack() In an offensive position."));
    
}

void APMHumanAIController::Attack()
{
    Super::Attack();
    
    SetState(EAIState::EAI_Attack);

    UE_LOG(LogTemp, Warning, TEXT("APMHumanAIController::Attack() Attacking."));

}