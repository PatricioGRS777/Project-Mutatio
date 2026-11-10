#include "Actors/PMDoorActor.h"

APMDoorActor::APMDoorActor(){
    PrimaryActorTick.bCanEverTick = true;
}

void APMDoorActor::Interact()
{
    UE_LOG(LogTemp, Log, TEXT("Door interaction received: %s"), *GetName());
    bShouldOpen ^= 1;       // a trick that occurred to me to flip a boolean
}

void APMDoorActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    FVector OpenLocation = ClosedLocation + FVector(0.0f, 250.0f, 0.0f);
    FVector TargetLocation = bShouldOpen ? OpenLocation : ClosedLocation;
    FVector NewLocation = FMath::VInterpConstantTo(
        StaticMesh->GetRelativeTransform().GetLocation(), TargetLocation, DeltaTime, 180.0f);
    StaticMesh->SetRelativeLocation(NewLocation);
}

void APMDoorActor::BeginPlay()
{
    Super::BeginPlay();
    ClosedLocation = StaticMesh->GetRelativeTransform().GetLocation();
}