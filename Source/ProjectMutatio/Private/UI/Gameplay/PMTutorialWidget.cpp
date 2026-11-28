


#include "PMTutorialWidget.h"
#include "Components/SizeBox.h"
#include "Components/Overlay.h"
#include "Components/HorizontalBox.h"
#include "Components/Image.h"
#include "Engine/Texture2D.h"
#include "Components/TextBlock.h"

void UPMTutorialWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (!TutorialSizeBox || !TutorialOverlay || !TutorialHorizontalBox ||
        !TutorialImage || !TutorialText)
    {
        UE_LOG(LogTemp, Error, TEXT("UPMTutorialWidget::NativeConstruct() The components are not valid. Make sure to fill the widget."));
        return;
    }
}

void UPMTutorialWidget::SetContent(class UTexture2D* NewTexture, FString NewText)
{
    TutorialImage->SetBrushFromTexture(NewTexture, false);

    TutorialText->SetText(FText::FromString(NewText));
}