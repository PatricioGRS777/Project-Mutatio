#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PMHealthComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PROJECTMUTATIO_API UPMHealthComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UPMHealthComponent();

    UFUNCTION(BlueprintCallable, Category = "Health")
    void ReduceLife(float DamageAmount);

    UFUNCTION(BlueprintPure, Category = "Health")
    float GetCurrentHealth() const { return CurrentHealth; }

    UFUNCTION(BlueprintPure, Category = "Health")
    float GetMaxHealth() const { return MaxHealth; }

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Health", meta = (ClampMin = "0.0"))
    float MaxHealth;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Health")
    float CurrentHealth;
};
