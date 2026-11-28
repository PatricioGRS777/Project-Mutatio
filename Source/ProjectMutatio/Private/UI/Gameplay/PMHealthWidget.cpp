


#include "PMHealthWidget.h"
#include "Components/HorizontalBox.h"
#include "Engine/Texture2D.h"
#include "Components/ProgressBar.h"
#include "Styling/SlateStyle.h"
#include "Styling/SlateTypes.h"
#include "Characters/Humans/PlayerCharacter/PMPlayerCharacter.h"
#include "Components/PMHealthComponent.h"
#include "Kismet/GameplayStatics.h"

void UPMHealthWidget::NativeConstruct()
{
    Super::NativeConstruct();
    if (!HealthBar || !CharacterImage)
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

    BackgroundTexture = LoadObject<UTexture2D>
        (nullptr, TEXT("/Game/Textures/Textures/UI/Gameplay/T_HealthBarEmpty.T_HealthBarEmpty"));

    FullTexture = LoadObject<UTexture2D>
        (nullptr, TEXT("/Game/Textures/Textures/UI/Gameplay/T_HealthBarFull.T_HealthBarFull"));

    if (!BackgroundTexture || !FullTexture)
    {
        UE_LOG(LogTemp, Error, TEXT("UPMHealthWidget::InitializeVariables() Progress bar textures are null."));
    }

    SetProgressBar(HealthBar, BackgroundTexture, FullTexture);
}

void UPMHealthWidget::SetProgressBar(UProgressBar* NewProgressBar, UTexture2D* EmptyTexture, UTexture2D* FillTexture)
{
    if (!NewProgressBar || !EmptyTexture || !FillTexture)
    {
        UE_LOG(LogTemp, Error, TEXT("SetProgressBar: Invalid parameters."));
        return;
    }

    FSlateBrush BackgroundBrush;
    BackgroundBrush.SetResourceObject(EmptyTexture);
    BackgroundBrush.DrawAs = ESlateBrushDrawType::Image;
    BackgroundBrush.ImageSize = FVector2D(
        EmptyTexture->GetSizeX(),
        EmptyTexture->GetSizeY()
    );

    FSlateBrush FillBrush;
    FillBrush.SetResourceObject(FillTexture);
    FillBrush.DrawAs = ESlateBrushDrawType::Image;
    FillBrush.ImageSize = FVector2D(
        FillTexture->GetSizeX(),
        FillTexture->GetSizeY()
    );

    NewProgressBar->WidgetStyle.SetBackgroundImage(BackgroundBrush);
    NewProgressBar->WidgetStyle.SetFillImage(FillBrush);

    NewProgressBar->SynchronizeProperties();
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