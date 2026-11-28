

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PMTutorialWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTMUTATIO_API UPMTutorialWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	void SetContent(class UTexture2D* NewTexture, FString NewText);


public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget), Category = "UI|Size Box")
	class USizeBox* TutorialSizeBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget), Category = "UI|Overlay")
	class UOverlay* TutorialOverlay;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget), Category = "UI|Horizontal Box")
	class UHorizontalBox* TutorialHorizontalBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget), Category = "UI|Images")
	class UImage* BackgroundImage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget), Category = "UI|Images")
	class UImage* TutorialImage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget), Category = "UI|Texts")
	class UTextBlock* TutorialText;
	
};
