#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PMDamageActor.generated.h"

class UBoxComponent;

/** Applies continuous damage to pawns with a health component inside its volume. */
UCLASS()
class PROJECTMUTATIO_API APMDamageActor : public AActor
{
    GENERATED_BODY()

public:
    APMDamageActor();

    virtual void Tick(float DeltaTime) override;

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UBoxComponent* DamageVolume;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage", meta = (ClampMin = "0.0"))
    float DamagePerSecond;
};
