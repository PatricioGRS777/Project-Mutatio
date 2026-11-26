


#include "PMCapturedMonstersWidget.h"
#include "Components/HorizontalBox.h"
#include "Components/Image.h"
#include "Components/Overlay.h"
#include "Components/TextBlock.h"

void UPMCapturedMonstersWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (!CapturedHorizontalBox || !MonsterImage || !MonsterBackgroundImage || 
        !MonsterOverlay || !CapturedMonstersText)
    {
        UE_LOG(LogTemp, Error, TEXT("UPMCapturedMonstersWidget::NativeConstruct() The components are not valid. Make sure to fill your widget with components."));
        return;
    }

    CapturedMonstersText->SetText(FText::FromString(TEXT("1 / 3")));
}
