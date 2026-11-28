

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

	virtual void NativeTick(const FGeometry& Geometry, float DeltaTime);

	void InitializeVariables();
	
	UFUNCTION()
	void UpdateMonsterCount();

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget), Category = "UI|Horizontal Box")
	class UHorizontalBox* CapturedHorizontalBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget), Category = "UI|Images")
	class UImage* MonsterImage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget), Category = "UI|Images")
	class UImage* MonsterBackgroundImage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget), Category = "UI|Overlay")
	class UOverlay* MonsterOverlay;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget), Category = "UI|Texts")
	class UTextBlock* CapturedMonstersText;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game Mode")
	class APMGameMode* PMGameMode;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player Character")
	class APMPlayerCharacter* PlayerCharacter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game Mode")
	FTimerHandle NewTimer;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game Mode")
	float NewDelay = 1.0f;
	
};
