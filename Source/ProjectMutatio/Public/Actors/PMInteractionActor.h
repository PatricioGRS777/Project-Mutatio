#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PMInteractionActor.generated.h"

UCLASS()
class PROJECTMUTATIO_API APMInteractionActor : public AActor
{
    GENERATED_BODY()

public:
    APMInteractionActor();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    class USceneComponent* SceneComp;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")

    class UStaticMeshComponent* StaticMesh;
};
