

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PMHUDWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTMUTATIO_API UPMHUDWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	virtual void NativeConstruct() override;

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget = true), Category = "UI|Overlay")
	class UCanvasPanel* HUDCanvasPanel;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget = true), Category = "UI|Vertical Box")
	class UVerticalBox* HUDVerticalBox;

};
