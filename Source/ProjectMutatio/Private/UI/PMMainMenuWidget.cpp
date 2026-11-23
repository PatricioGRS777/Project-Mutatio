


#include "PMMainMenuWidget.h"
#include "Components/CanvasPanel.h"
#include "Components/SizeBox.h"
#include "Components/Overlay.h"
#include "Components/VerticalBox.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

void UPMMainMenuWidget::NativeConstruct()
{
    if (!MenuCanvasPanel || !MenuSizeBox || !MenuVerticalBox ||
        !NewGameButton || !HowToPlayButton || !CreditsButton ||
        !ExitGameButton || !TitleLogoImage || !ToFullScreenImage ||
        !NewGameText || !HowToPlayText || !CreditsText ||
        !ExitGameText)
    {
        UE_LOG(LogTemp, Error, TEXT("UPMMainMenuWidget::NativeConstruct() The components are not valid. Make sure to add the components inside the widget."));
        return;
    }

    NewGameButton->OnClicked.AddDynamic(this, &UPMMainMenuWidget::OnNewGamePressed);
    HowToPlayButton->OnClicked.AddDynamic(this, &UPMMainMenuWidget::OnHowToPlayPressed);
    CreditsButton->OnClicked.AddDynamic(this, &UPMMainMenuWidget::OnCreditsPressed);
    ExitGameButton->OnClicked.AddDynamic(this, &UPMMainMenuWidget::OnExitGamePressed);

    NewGameText->SetText(FText::FromString(TEXT("New Game")));
    HowToPlayText->SetText(FText::FromString(TEXT("How to Play")));
    CreditsText->SetText(FText::FromString(TEXT("Credits")));
    ExitGameText->SetText(FText::FromString(TEXT("Exit Game")));
}

void UPMMainMenuWidget::OnNewGamePressed()
{
    UE_LOG(LogTemp, Warning, TEXT("UPMMainMenuWidget::OnNewGamePressed() New Game."));
}

void UPMMainMenuWidget::OnHowToPlayPressed()
{
    UE_LOG(LogTemp, Warning, TEXT("UPMMainMenuWidget::OnHowToPlayPressed() How to Play."));
}

void UPMMainMenuWidget::OnCreditsPressed()
{
    UE_LOG(LogTemp, Warning, TEXT("UPMMainMenuWidget::OnCreditsPressed() Credits."));
}

void UPMMainMenuWidget::OnExitGamePressed()
{
    UE_LOG(LogTemp, Warning, TEXT("UPMMainMenuWidget::OnExitGamePressed() Exit Game."));
}
