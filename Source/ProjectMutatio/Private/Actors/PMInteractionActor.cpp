#include "Actors/PMInteractionActor.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"

APMInteractionActor::APMInteractionActor()
{
    PrimaryActorTick.bCanEverTick = false;

    // setup root and attachment
    SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComp"));
    SetRootComponent(SceneComp);

    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMesh->SetupAttachment(SceneComp);
}
