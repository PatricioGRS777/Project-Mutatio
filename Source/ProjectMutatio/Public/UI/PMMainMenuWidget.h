

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

	void OnNewGamePressed();

	void OnHowToPlayPressed();

	void OnCreditsPressed();

	void OnExitGamePressed();

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget = true), Category = "Canvas Panel")
	class UCanvasPanel* MenuCanvasPanel;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget = true), Category = "Size Box")
	class USizeBox* MenuSizeBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget = true), Category = "Vertical Box")
	class UVerticalBox* MenuVerticalBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget = true), Category = "Buttons")
	class UButton* NewGameButton;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget = true), Category = "Buttons")
	class UButton* HowToPlayButton;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget = true), Category = "Buttons")
	class UButton* CreditsButton;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget = true), Category = "Buttons")
	class UButton* ExitGameButton;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget = true), Category = "Overlay")
	class UOverlay* ToFullScreenOverlay;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget = true), Category = "Images")
	class UImage* TitleLogoImage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget = true), Category = "Images")
	class UImage* ToFullScreenImage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget = true), Category = "Texts")
	class UTextBlock* NewGameText;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget = true), Category = "Texts")
	class UTextBlock* HowToPlayText;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget = true), Category = "Texts")
	class UTextBlock* CreditsText;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget = true), Category = "Texts")
	class UTextBlock* ExitGameText;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget = true), Category = "Texts")
	class UTextBlock* ToFullScreenText;


};
