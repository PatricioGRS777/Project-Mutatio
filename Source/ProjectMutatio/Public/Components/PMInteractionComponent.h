#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PMInteractionComponent.generated.h"

UCLASS()
class PROJECTMUTATIO_API UPMInteractionComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UPMInteractionComponent();
    void Interact();
};