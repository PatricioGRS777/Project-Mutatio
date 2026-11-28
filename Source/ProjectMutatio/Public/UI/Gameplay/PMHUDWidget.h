

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
	
	void InitializeVariables(APawn* InPawn);

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget), Category = "UI|Overlay")
	class UCanvasPanel* HUDCanvasPanel;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget), Category = "UI")
	class UPMHealthWidget* WBP_HealthBar;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget), Category = "UI")
	class UPMCapturedMonstersWidget* WBP_CapturedMonsters;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI")
	class APMPlayerCharacter* PlayerCharacter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI")
	class UPMHealthComponent* HealthComponent;


};
