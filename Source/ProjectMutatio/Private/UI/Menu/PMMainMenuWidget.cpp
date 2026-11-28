


#include "PMMainMenuWidget.h"
#include "Components/CanvasPanel.h"
#include "Components/SizeBox.h"
#include "Components/Overlay.h"
#include "Components/VerticalBox.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"

void UPMMainMenuWidget::NativeConstruct()
{
    if (!MenuCanvasPanel || !TitleSizeBox || !MenuVerticalBox ||
        !NewGameButton || !HowToPlayButton || !CreditsButton ||
        !NewGameText || !HowToPlayText || !CreditsText ||
        !ToFullscreenText || !TitleLogoImage || !ToFullScreenImage ||
        !NewGameText || !HowToPlayText || !CreditsText)
    {
        UE_LOG(LogTemp, Error, TEXT("UPMMainMenuWidget::NativeConstruct() The components are not valid. Make sure to add the components inside the widget."));
        return;
    }

    NewGameButton->OnClicked.AddDynamic(this, &UPMMainMenuWidget::OnNewGamePressed);
    HowToPlayButton->OnClicked.AddDynamic(this, &UPMMainMenuWidget::OnHowToPlayPressed);
    CreditsButton->OnClicked.AddDynamic(this, &UPMMainMenuWidget::OnCreditsPressed);

    NewGameText->SetText(FText::FromString(TEXT("New Game")));
    HowToPlayText->SetText(FText::FromString(TEXT("How to Play")));
    CreditsText->SetText(FText::FromString(TEXT("Credits")));
    ToFullscreenText->SetText(FText::FromString(TEXT("To full screen")));
}

void UPMMainMenuWidget::OnNewGamePressed()
{
    UE_LOG(LogTemp, Warning, TEXT("UPMMainMenuWidget::OnNewGamePressed() New Game."));

    UGameplayStatics::OpenLevel(GetWorld(), FName("L_DebugRoom"));
}

void UPMMainMenuWidget::OnHowToPlayPressed()
{
    UE_LOG(LogTemp, Warning, TEXT("UPMMainMenuWidget::OnHowToPlayPressed() How to Play."));
}

void UPMMainMenuWidget::OnCreditsPressed()
{
    UE_LOG(LogTemp, Warning, TEXT("UPMMainMenuWidget::OnCreditsPressed() Credits."));
}