

#include "PMBaseAIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Characters/Humans/PlayerCharacter/PMPlayerCharacter.h"
#include "Characters/Humans/Guards/PMGuardCharacter.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AISenseConfig_Hearing.h"
#include "Perception/AIPerceptionTypes.h"
#include "NavigationSystem.h"


APMBaseAIController::APMBaseAIController()
{
    PerceptionComp = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AI Perception Component"));
    SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("AI Sight Config"));
    HearingConfig = CreateDefaultSubobject<UAISenseConfig_Hearing>(TEXT("AI Hearing Config"));

    SightConfig->SightRadius = 500.0f;
    SightConfig->LoseSightRadius = 1000.0f;
    SightConfig->PeripheralVisionAngleDegrees = 75.0f;

    HearingConfig->HearingRange = 500.0f;
    HearingConfig->LoSHearingRange = 1000.0f;

    SightConfig->DetectionByAffiliation.bDetectEnemies = true;
    SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
    SightConfig->DetectionByAffiliation.bDetectFriendlies = true;

    HearingConfig->DetectionByAffiliation.bDetectEnemies = true;
    HearingConfig->DetectionByAffiliation.bDetectNeutrals = true;
    HearingConfig->DetectionByAffiliation.bDetectFriendlies = true;

    PerceptionComp->ConfigureSense(*SightConfig);
    PerceptionComp->ConfigureSense(*HearingConfig);

    SetPerceptionComponent(*PerceptionComp);
}

void APMBaseAIController::BeginPlay()
{
    Super::BeginPlay();

    InitializeVariables();  

}

void APMBaseAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    const FString StateText = UEnum::GetValueAsString(AIState);

    UE_LOG(LogTemp, Warning, TEXT("APMBaseAIController::Tick() Character State: %s"), *StateText);

    UpdateCharacterState(AIState);
}


void APMBaseAIController::InitializeVariables()
{
    ControlledPawn = GetPawn();

    if (!ControlledPawn)
    {
        UE_LOG(LogTemp, Error, TEXT("APMBaseAIController::InitializeVariables() ControlledPawn is null."));
        return;
    }
}

void APMBaseAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

    if (!PerceptionComp)
    {
        UE_LOG(LogTemp, Error, TEXT("APMBaseAIController::OnPossess() AIPerceptionComponent is null."));
        return;
    }

    PerceptionComp->OnTargetPerceptionUpdated.AddDynamic(this, &APMBaseAIController::OnPerceptionUpdated);

    ReceiveMoveCompleted.AddDynamic(this, &APMBaseAIController::OnMoveCompleted);

}

void APMBaseAIController::OnPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{

}

void APMBaseAIController::OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result)
{

}

void APMBaseAIController::SetState(EAIState NewState)
{
    AIState = NewState;

}

void APMBaseAIController::UpdateCharacterState(EAIState CurrentState)
{
    switch (CurrentState)
    {
        case EAIState::EAI_None :

            UE_LOG(LogTemp, Warning, TEXT("APMBaseAIController::SetState() Theres no a valid state. Set a state for this character."));

            break;

        case EAIState::EAI_Idle :

            break;

        case EAIState::EAI_Patrol :

            break;

        case EAIState::EAI_Investigate :

            break;

        case EAIState::EAI_Chase :

            break;

        case EAIState::EAI_Offensive :

            break;

        case EAIState::EAI_Attack :

            break;

        case EAIState::EAI_Disguise :

            break;

        case EAIState::EAI_Unconscious :

            break;
    }
}

void APMBaseAIController::Idle()
{

}

void APMBaseAIController::Patrol()
{

}

void APMBaseAIController::Investigate()
{

}

void APMBaseAIController::Chase()
{

}

void APMBaseAIController::Offensive()
{

}

void APMBaseAIController::Attack()
{

}

void APMBaseAIController::Unconscious()
{

}