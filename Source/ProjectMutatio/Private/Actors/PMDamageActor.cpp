#include "Actors/PMDamageActor.h"
#include "Components/BoxComponent.h"
#include "Components/PMHealthComponent.h"

APMDamageActor::APMDamageActor()
{
    PrimaryActorTick.bCanEverTick = true;

    DamagePerSecond = 10.0f;

    DamageVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("Damage Volume"));
    SetRootComponent(DamageVolume);
    DamageVolume->InitBoxExtent(FVector(100.0f, 100.0f, 100.0f));
    DamageVolume->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    DamageVolume->SetCollisionObjectType(ECC_WorldDynamic);
    DamageVolume->SetCollisionResponseToAllChannels(ECR_Ignore);
    DamageVolume->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
    DamageVolume->SetGenerateOverlapEvents(true);
}

void APMDamageActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (DamagePerSecond <= 0.0f || DeltaTime <= 0.0f)
    {
        return;
    }

    TArray<AActor*> OverlappingActors;
    DamageVolume->GetOverlappingActors(OverlappingActors);

    // GetOverlappingActors returns each actor once, even if several components overlap.
    for (AActor* Actor : OverlappingActors)
    {
        if (!IsValid(Actor))
        {
            continue;
        }

        if (UPMHealthComponent* Health = Actor->FindComponentByClass<UPMHealthComponent>())
        {
            Health->ReduceLife(DamagePerSecond * DeltaTime);
        }
    }
}
