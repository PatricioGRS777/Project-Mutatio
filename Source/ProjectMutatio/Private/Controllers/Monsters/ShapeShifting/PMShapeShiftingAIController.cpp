


#include "PMShapeShiftingAIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Characters/Monsters/ShapeShifting/PMShapeShiftingCharacter.h"
#include "Characters/Humans/PlayerCharacter/PMPlayerCharacter.h"
#include "Kismet/KismetMathLibrary.h"

APMShapeShiftingAIController::APMShapeShiftingAIController()
{

}

void APMShapeShiftingAIController::BeginPlay()
{
    Super::BeginPlay();

    Idle();
}

void APMShapeShiftingAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    UpdateCharacterState(AIState);

    if (AIState == EAIState::EAI_Chase)
    {
        float DistanceToPlayer = FVector::Dist(PawnLocation, PlayerLocation);

        if (DistanceToPlayer <= 500.0f)
        {
            Offensive();
        }
    }

}

void APMShapeShiftingAIController::InitializeVariables()
{
    Super::InitializeVariables();

    ShiftingCharacter = Cast<APMShapeShiftingCharacter>(ControlledPawn);

    if (!ShiftingCharacter)
    {
        UE_LOG(LogTemp, Error, TEXT("APMShapeShiftingAIController::InitializeVariables() ShiftingCharacter is null."));
        return;
    }

}

void APMShapeShiftingAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

    PerceptionComp->OnTargetPerceptionUpdated.AddUniqueDynamic(this, &APMShapeShiftingAIController::OnPerceptionUpdated);

    ReceiveMoveCompleted.AddUniqueDynamic(this, &APMShapeShiftingAIController::OnMoveCompleted);
}

void APMShapeShiftingAIController::OnPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
    Super::OnPerceptionUpdated(Actor, Stimulus);

    APMPlayerCharacter* DetectedPlayer = Cast<APMPlayerCharacter>(Actor);

    if (!DetectedPlayer)
    {
        UE_LOG(LogTemp, Warning, TEXT("APMShapeShiftingAIController::OnPerceptionUpdated() DetectedPlayer is null."));
        return;
    }

    if (Stimulus.WasSuccessfullySensed() && AIState == EAIState::EAI_Chase)
    {
        PlayerCharacter = DetectedPlayer;

        PlayerLocation = PlayerCharacter->GetActorLocation();

        Chase();
    }


}

void APMShapeShiftingAIController::OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result)
{
    Super::OnMoveCompleted(RequestID, Result);

    switch (Result)
    {
        case EPathFollowingResult::Success :
            UE_LOG(LogTemp, Warning, TEXT("APMShapeShiftingAIController::OnMoveCompleted() Character reach destiny."));

            if (AIState == EAIState::EAI_Disguise)
            {
                Idle();
            }

            break;

        case EPathFollowingResult::Blocked :
            UE_LOG(LogTemp, Warning, TEXT("APMShapeShiftingAIController::OnMoveCompleted() The path is blocked."));

            break;

        case EPathFollowingResult::Aborted :
            UE_LOG(LogTemp, Warning, TEXT("APMShapeShiftingAIController::OnMoveCompleted() Aborted."));

            break;
    }
}

void APMShapeShiftingAIController::Idle()
{
    Super::Idle();

    AIState = EAIState::EAI_Idle;

}

void APMShapeShiftingAIController::Disguise()
{    
    if (!ShiftingCharacter)
    {
        UE_LOG(LogTemp, Error, TEXT("APMShapeShiftingAIController::Disguise() ShiftingCharacter is null."));
        return;
    }

    if (ShiftingCharacter->DisguisePoints.Num() == 0)
    {
        UE_LOG(LogTemp, Error, TEXT("APMShapeShiftingAIController::Disguise() DisguisePoints array is empty. Make sure to fill the array with actors."));
        return;
    }

    int32 RandIndex = FMath::RandRange(0, ShiftingCharacter->DisguisePoints.Num() - 1);

    AActor* DisguiseActor = ShiftingCharacter->DisguisePoints[RandIndex];

    if (!DisguiseActor)
    {
        UE_LOG(LogTemp, Error, TEXT("APMShapeShiftingAIController::Disguise() DisguiseActor is null."));
        return;
    }

    SetState(EAIState::EAI_Disguise);

    FVector DisguiseLocation = DisguiseActor->GetActorLocation();

    MoveToLocation(DisguiseLocation, 25.0f);
}

void APMShapeShiftingAIController::Chase()
{
    Super::Chase();

    SetState(EAIState::EAI_Chase);

    UE_LOG(LogTemp, Warning, TEXT("APMShapeShiftingAIController::Chase() Chasing the player."));

    PawnLocation = ShiftingCharacter->GetActorLocation();

    PlayerLocation = PlayerCharacter->GetActorLocation();

    MoveToActor(PlayerCharacter, 200.0f);

}

void APMShapeShiftingAIController::Offensive()
{
    Super::Offensive();

    SetState(EAIState::EAI_Offensive);

    UE_LOG(LogTemp, Warning, TEXT("APMShapeShiftingAIController::Offensive() In offensive position."));

    GetWorldTimerManager().SetTimer(
        OffensiveTimer,
        this,
        &APMShapeShiftingAIController::Attack,
        0.25f,
        false);
}

void APMShapeShiftingAIController::Attack()
{
    Super::Attack();

    if (!ShiftingCharacter)
    {
        UE_LOG(LogTemp, Error, TEXT("APMShapeShiftingAIController::Attack() ShiftingCharacter is null."));
        return;
    }

    if (!PlayerCharacter)
    {
        UE_LOG(LogTemp, Error, TEXT("APMShapeShiftingAIController::Attack() PlayerCharacter is null."));
        return;
    }

    SetState(EAIState::EAI_Attack);

    StopMovement();

    AttackPreparationTime = FMath::RandRange(2.0f, 3.0f);

    AttackStartLocation = ShiftingCharacter->GetActorLocation();

    AttacksRemaining = FMath::RandRange(2, 5);

    GetWorldTimerManager().SetTimer(
        AttackPhaseTimer,
        this,
        &APMShapeShiftingAIController::BeginAttack,
        AttackPreparationTime,
        false);

}

void APMShapeShiftingAIController::BeginAttack()
{
    Super::BeginAttack();

    if (!ShiftingCharacter)
    {
        UE_LOG(LogTemp, Error, TEXT("APMShapeShiftingAIController::BeginAttack() ShiftingCharacter is null."));
        return;
    }

    if (!PlayerCharacter)
    {
        UE_LOG(LogTemp, Error, TEXT("APMShapeShiftingAIController::BeginAttack() PlayerCharacter is null."));
        return;
    }    

    FVector Direction = PlayerCharacter->GetActorLocation() - ShiftingCharacter->GetActorLocation();

    Direction.Z = 0.0f;

    Direction.Normalize();

    ShiftingCharacter->LaunchCharacter(
        Direction * 4200.0f,
        true,
        false);

    GetWorldTimerManager().SetTimer(
        AttackPhaseTimer,
        this,
        &APMShapeShiftingAIController::ReturnToStart,
        AttackDuration,
        false);
}

void APMShapeShiftingAIController::ReturnToStart()
{
    Super::ReturnToStart();

    if (!ShiftingCharacter)
    {
        UE_LOG(LogTemp, Error, TEXT("APMShapeShiftingAIController::ReturnToStart() ShiftingCharacter is null."));
        return;
    }

    if (!PlayerCharacter)
    {
        UE_LOG(LogTemp, Error, TEXT("APMShapeShiftingAIController::ReturnToStart() PlayerCharacter is null."));
        return;
    }    

    AttackCooldown = FMath::RandRange(2.0f, 5.0f);

    FVector Direction = AttackStartLocation - PlayerCharacter->GetActorLocation();

    Direction.Z = 0.0f;

    Direction.Normalize();

    ShiftingCharacter->LaunchCharacter(
        Direction * 1200.0f,
        true,
        false);

    GetWorldTimerManager().SetTimer(
        AttackPhaseTimer,
        this,
        &APMShapeShiftingAIController::ContinueAttack,
        AttackCooldown,
        false);
}

void APMShapeShiftingAIController::ContinueAttack()
{
    Super::ContinueAttack();
    
    AttacksRemaining--;

    if (AttacksRemaining > 0)
    {
        BeginAttack();
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("APMShapeShiftingAIController::ContinueAttack() Move to disguise location."));

        Disguise();
    }
}