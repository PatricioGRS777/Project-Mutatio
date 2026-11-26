


#include "PMHealthWidget.h"
#include "Components/HorizontalBox.h"
#include "Components/Image.h"
#include "Components/ProgressBar.h"
#include "Characters/Humans/PlayerCharacter/PMPlayerCharacter.h"
#include "Components/PMHealthComponent.h"
#include "Kismet/GameplayStatics.h"

void UPMHealthWidget::NativeConstruct()
{
    Super::NativeConstruct();
    if (!HealthBar || !CharacterImage || !EmptyHealthImage || !FullHealthImage)
    {
        UE_LOG(LogTemp, Error, TEXT("UPMHealthWidget::NativeConstruct() The components are not valid. Make sure to add the components inside the widget."));
        return;
    }

    InitializeVariables();
}


void UPMHealthWidget::NativeTick(const FGeometry& Geometry, float DeltaTime)
{
    Super::NativeTick(Geometry, DeltaTime);

    UpdateHealthBar();
}

void UPMHealthWidget::InitializeVariables()
{
    if(!PlayerCharacter)
    {
        UE_LOG(LogTemp, Error, TEXT("UPMHealthWidget::InitializeVariables() PlayerCharacter is null."));
        return;
    }

    if (!HealthComponent)
    {
        UE_LOG(LogTemp, Error, TEXT("UPMHealthWidget::InitializeVariables() HealthComponent is null."));
        return;
    }
}

void UPMHealthWidget::UpdateHealthBar()
{
    if (!HealthComponent)
    {
        UE_LOG(LogTemp, Error, TEXT("UPMHealthWidget::UpdateHealthBar() HealthComponent is null."));
        return;
    }
    CurrentHealth = HealthComponent->CurrentHealth;

    MaxHealth = HealthComponent->MaxHealth;

    float Percent = FMath::Clamp(CurrentHealth / MaxHealth, 0.0f, 1.0f);

    UE_LOG(LogTemp, Warning, TEXT("UPMHealthWidget::UpdateHealthBar() Health: %f"), Percent);

    HealthBar->SetPercent(Percent);
}