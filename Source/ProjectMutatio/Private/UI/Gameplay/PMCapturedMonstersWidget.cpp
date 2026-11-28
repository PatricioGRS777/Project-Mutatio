


#include "PMCapturedMonstersWidget.h"
#include "Components/SizeBox.h"
#include "Components/HorizontalBox.h"
#include "Components/Image.h"
#include "Components/Overlay.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/GameModeBase.h"
#include "Core/PMGameMode.h"
#include "Characters/Humans/PlayerCharacter/PMPlayerCharacter.h"
#include "Components/PMSoulVacuumComponent.h"
#include "TimerManager.h"

void UPMCapturedMonstersWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (!CapturedHorizontalBox || !MonsterImage || !MonsterBackgroundImage || 
        !MonsterOverlay || !CapturedMonstersText)
    {
        UE_LOG(LogTemp, Error, TEXT("UPMCapturedMonstersWidget::NativeConstruct() The components are not valid. Make sure to fill your widget with components."));
        return;
    }

    CapturedMonstersText->SetText(FText::FromString(TEXT("")));

    InitializeVariables();

    GetWorld()->GetTimerManager().SetTimer(
        NewTimer,
        this,
        &UPMCapturedMonstersWidget::UpdateMonsterCount,
        NewDelay,
        false);
}

void UPMCapturedMonstersWidget::NativeTick(const FGeometry& Geometry, float DeltaTime)
{
    Super::NativeTick(Geometry, DeltaTime);

}

void UPMCapturedMonstersWidget::InitializeVariables()
{
    PMGameMode = Cast<APMGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

    if (!PMGameMode)
    {
        UE_LOG(LogTemp, Error, TEXT("UPMCapturedMonstersWidget::InitializeVariables() PMGameMode is null."));
        return;
    }

    PlayerCharacter = Cast<APMPlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

    if (!PlayerCharacter)
    {
        UE_LOG(LogTemp, Error, TEXT("UPMCapturedMonstersWidget::InitializeVariables() PlayerCharacter is null."));
        return;
    }

    UPMSoulVacuumComponent* VacuumComponent = Cast<UPMSoulVacuumComponent>(
        PlayerCharacter->GetComponentByClass(UPMSoulVacuumComponent::StaticClass()));

    if (!VacuumComponent)
    {
        UE_LOG(LogTemp, Error, TEXT("UPMCapturedMonstersWidget::InitializeVariables() VacuumComponent is null."));
        return;
    }

    VacuumComponent->OnMonstersCountChanged.AddUniqueDynamic(this, &UPMCapturedMonstersWidget::UpdateMonsterCount);
}

void UPMCapturedMonstersWidget::UpdateMonsterCount()
{
    if (!PMGameMode)
    {
        UE_LOG(LogTemp, Error, TEXT("UPMCapturedMonstersWidget::UpdateMonsterCount() PMGameMode is null."));
        return;
    }

    int32 CapturedMonstersCount = PMGameMode->CapturedMonstersCount;
    int32 TotalMonstersCount = PMGameMode->TotalMonsterCount;

    CapturedMonstersText->SetText(FText::FromString(FString::Printf(TEXT("%d / %d"), CapturedMonstersCount, TotalMonstersCount)));
}