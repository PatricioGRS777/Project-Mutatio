


#include "PMHealthWidget.h"

void UPMHealthWidget::NativeConstruct()
{
    if (!HealthBar || !CharacterImage || !EmptyHealthImage || !FullHealthImage)
    {
        UE_LOG(LogTemp, Error, TEXT("UPMHealthWidget::NativeConstruct() The components are not valid. Make sure to add the components inside the widget."))
        return;
    }
}