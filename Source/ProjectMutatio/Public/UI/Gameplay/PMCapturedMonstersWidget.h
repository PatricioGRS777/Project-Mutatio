

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PMCapturedMonstersWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTMUTATIO_API UPMCapturedMonstersWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget = true), Category = "UI|Horizontal Box")
	class UHorizontalBox* CapturedHorizontalBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget = true), Category = "UI|Horizontal Box")
	class UImage* MonsterImage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget = true), Category = "UI|Horizontal Box")
	class UImage* MonsterBackgroundImage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget = true), Category = "UI|Horizontal Box")
	class UOverlay* MonsterOverlay;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget = true), Category = "UI|Horizontal Box")
	class UTextBlock* CapturedMonstersText;
	
};
