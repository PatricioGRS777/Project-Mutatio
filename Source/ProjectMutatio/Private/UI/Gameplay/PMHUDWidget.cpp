


#include "PMHUDWidget.h"
#include "Components/CanvasPanel.h"
#include "Components/VerticalBox.h"
#include "UI/Gameplay/PMHealthWidget.h"
#include "UI/Gameplay/PMCapturedMonstersWidget.h"
#include "Characters/Humans/PlayerCharacter/PMPlayerCharacter.h"
#include "Components/PMHealthComponent.h"

void UPMHUDWidget::NativeConstruct()
{
    if (!HUDCanvasPanel || !WBP_HealthBar || !WBP_CapturedMonsters)
    {
        UE_LOG(LogTemp, Error, TEXT("UPMHUDWidget::NativeConstruct() The components are not valid. Make sure to add the components inside the widget."));
        return;
    }
}

void UPMHUDWidget::InitializeVariables(APawn* InPawn)
{
    PlayerCharacter = Cast<APMPlayerCharacter>(InPawn);

    if(!PlayerCharacter)
    {
        UE_LOG(LogTemp, Error, TEXT("UPMHUDWidget::InitializeVariables() PlayerCharacter is null."));
        return;
    }

    HealthComponent = Cast<UPMHealthComponent>(PlayerCharacter->GetComponentByClass(UPMHealthComponent::StaticClass()));

    if (!HealthComponent)
    {
        UE_LOG(LogTemp, Error, TEXT("UPMHUDWidget::InitializeVariables() HealthComponent is null."));
        return;
    }

    if (!WBP_HealthBar)
    {
        UE_LOG(LogTemp, Error, TEXT("UPMHUDWidget::InitializeVariables() WBP_HealthBar is null."));
        return;
    }

    WBP_HealthBar->PlayerCharacter = PlayerCharacter;
    WBP_HealthBar->HealthComponent = HealthComponent;
}