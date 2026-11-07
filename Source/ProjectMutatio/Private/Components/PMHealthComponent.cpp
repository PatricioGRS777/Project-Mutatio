#include "Components/PMHealthComponent.h"

UPMHealthComponent::UPMHealthComponent()
{
    PrimaryComponentTick.bCanEverTick = false;

    MaxHealth = 100.0f;
    CurrentHealth = MaxHealth;
}

void UPMHealthComponent::BeginPlay()
{
    Super::BeginPlay();

    // Blueprint defaults are applied after the C++ constructor.
    MaxHealth = FMath::IsFinite(MaxHealth) ? FMath::Max(0.0f, MaxHealth) : 0.0f;
    CurrentHealth = MaxHealth;
}

void UPMHealthComponent::ReduceLife(float DamageAmount)
{
    if (!FMath::IsFinite(DamageAmount) || DamageAmount <= 0.0f || CurrentHealth <= 0.0f)
    {
        return;
    }

    CurrentHealth = FMath::Clamp(CurrentHealth - DamageAmount, 0.0f, MaxHealth);

    UE_LOG(LogTemp, Warning, TEXT("UPMHealthComponent::ReduceLife() Health: %f"), CurrentHealth);
}
