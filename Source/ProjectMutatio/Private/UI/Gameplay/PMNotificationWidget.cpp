


#include "PMNotificationWidget.h"
#include "Components/SizeBox.h"
#include "Components/Overlay.h"
#include "Components/HorizontalBox.h"
#include "Components/Image.h"
#include "Engine/Texture2D.h"
#include "Components/TextBlock.h"

void UPMNotificationWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (!NotificationSizeBox || !NotificationHorizontalBox || !NotificationOverlay ||
        !NotificationImage || !NotificationText)
    {
        UE_LOG(LogTemp, Error, TEXT("UPMNotificationWidget::NativeConstruct() The components are not valid. Make sure to fill the widget."));
        return;
    }
}


void UPMNotificationWidget::SetContent(class UTexture2D* NewTexture, FString NewText)
{
    NotificationImage->SetBrushFromTexture(NewTexture, false);

    NotificationText->SetText(FText::FromString(NewText));
}
