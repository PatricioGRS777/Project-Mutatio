


#include "PMHUDWidget.h"
#include "Components/CanvasPanel.h"
#include "Components/VerticalBox.h"

void UPMHUDWidget::NativeConstruct()
{
    if (!HUDCanvasPanel || !HUDVerticalBox)
    {
        UE_LOG(LogTemp, Error, TEXT("UPMHUDWidget::NativeConstruct() The components are not valid. Make sure to add the components inside the widget."));
        return;
    }
}