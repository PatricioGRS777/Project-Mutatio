

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PMMainMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTMUTATIO_API UPMMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativeConstruct();

	UFUNCTION()
	void OnNewGamePressed();

	UFUNCTION()
	void OnHowToPlayPressed();

	UFUNCTION()
	void OnCreditsPressed();

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget), Category = "Canvas Panel")
	class UCanvasPanel* MenuCanvasPanel;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget), Category = "Size Box")
	class USizeBox* TitleSizeBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget), Category = "Vertical Box")
	class UVerticalBox* MenuVerticalBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget), Category = "Buttons")
	class UButton* NewGameButton;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget), Category = "Buttons")
	class UButton* HowToPlayButton;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget), Category = "Buttons")
	class UButton* CreditsButton;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget), Category = "Overlay")
	class UOverlay* ToFullScreenOverlay;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget), Category = "Images")
	class UImage* TitleLogoImage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget), Category = "Images")
	class UImage* ToFullScreenImage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget), Category = "Texts")
	class UTextBlock* NewGameText;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget), Category = "Texts")
	class UTextBlock* HowToPlayText;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget), Category = "Texts")
	class UTextBlock* CreditsText;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget), Category = "Texts")
	class UTextBlock* ToFullscreenText;

};
