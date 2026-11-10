#pragma once

#include "Actors/PMInteractionActor.h"
#include "Interfaces/PMInteractionInterface.h"
#include "PMDoorActor.generated.h"

UCLASS()
class PROJECTMUTATIO_API APMDoorActor
    : public APMInteractionActor, public IPMInteractionInterface
{
    GENERATED_BODY()

public:
    void Interact() override;
    APMDoorActor();
    void Tick(float DeltaTime) override;

private: 
    bool bShouldOpen = false;
    void BeginPlay() override;
    FVector ClosedLocation = FVector::ZeroVector;
};
