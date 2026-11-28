


#include "PMCaptureBarWidget.h"
#include "Components/VerticalBox.h"
#include "Components/ProgressBar.h"
#include "Components/Image.h"
#include "Materials/MaterialInterface.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Engine/Texture2D.h"
#include "Kismet/GameplayStatics.h"
#include "Characters/Humans/PlayerCharacter/PMPlayerCharacter.h"
#include "Components/PMSoulVacuumComponent.h"


void UPMCaptureBarWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (!CaptureVerticalBox || !CaptureBar || !ButtonImage)
    {
        UE_LOG(LogTemp, Error, TEXT("UPMCaptureBarWidget::NativeConstruct() The components are not valid. Make sure to fill the widget with components."));
        return;
    }

    InitializeVariables();
}

void UPMCaptureBarWidget::InitializeVariables()
{
    PlayerCharacter = Cast<APMPlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

    if (!PlayerCharacter)
    {
        UE_LOG(LogTemp, Error, TEXT("UPMCaptureBarWidget::InitializeVariables() PlayerCharacter is null."));
        return;
    }

    VacuumComponent = Cast<UPMSoulVacuumComponent>(PlayerCharacter->GetComponentByClass(UPMSoulVacuumComponent::StaticClass()));

    if (!VacuumComponent)
    {
        UE_LOG(LogTemp, Error, TEXT("UPMCaptureBarWidget::InitializeVariables() VacuumComponent is null."));
        return;
    }

    BackgroundTexture = LoadObject<UTexture2D>(
        nullptr, TEXT("/Game/Textures/Textures/UI/Gameplay/Vacuum/T_VacuumProgressBarEmpty.T_VacuumProgressBarEmpty"));

    FillTexture = LoadObject<UTexture2D>
        (nullptr, TEXT("/Game/Textures/Textures/UI/Gameplay/Vacuum/T_VacuumProgressBarFull.T_VacuumProgressBarFull"));

    if (!BackgroundTexture || !FillTexture)
    {
        UE_LOG(LogTemp, Error, TEXT("UPMCaptureBarWidget::InitializeVariables() Texture are not valid."));
        return;
    }

    SetprogressBar(CaptureBar, BackgroundTexture, FillTexture);
}

void UPMCaptureBarWidget::NativeTick(const FGeometry& Geometry, float DeltaTime)
{
    Super::NativeTick(Geometry, DeltaTime);

    UpdateProgressBar();
}

void UPMCaptureBarWidget::SetprogressBar(class UProgressBar* NewProgressBar, class UTexture2D* EmptyTexture, class UTexture2D* FullTexture)
{
    if (!NewProgressBar || !EmptyTexture || !FullTexture)
    {
        return;
    }

    FSlateBrush BackgroundBrush;

    BackgroundBrush.SetResourceObject(EmptyTexture);
    BackgroundBrush.DrawAs = ESlateBrushDrawType::Image;
    BackgroundBrush.ImageSize = FVector2D(
        EmptyTexture->GetSizeX(),
        EmptyTexture->GetSizeY());

    FSlateBrush FullBrush;
    FullBrush.SetResourceObject(FullTexture);
    FullBrush.DrawAs = ESlateBrushDrawType::Image;
    FullBrush.ImageSize = FVector2D(
        EmptyTexture->GetSizeX(),
        EmptyTexture->GetSizeY());

    NewProgressBar->WidgetStyle.SetBackgroundImage(BackgroundBrush);
    NewProgressBar->WidgetStyle.SetFillImage(FullBrush);
}

void UPMCaptureBarWidget::UpdateProgressBar()
{
    if (!VacuumComponent)
    {
        return;
    }

    float CaptureProgress = VacuumComponent->CaptureProgress;

    float MaxCaptureProgress = VacuumComponent->MaxCaptureProgress;

    float Percent = FMath::Clamp(CaptureProgress / MaxCaptureProgress, 0.0f, 1.0f);

    CaptureBar->SetPercent(Percent);
}