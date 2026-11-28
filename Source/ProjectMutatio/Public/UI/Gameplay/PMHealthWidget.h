

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PMHealthWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTMUTATIO_API UPMHealthWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	virtual void NativeTick(const FGeometry& Geometry, float DeltaTime) override;

	void InitializeVariables();

	void SetProgressBar(class UProgressBar* NewProgressBar, class UTexture2D* EmptyTexture, class UTexture2D* FillTexture);

	void UpdateHealthBar();

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget), Category = "UI|Progress Bar")
	class UHorizontalBox* HealthHorizontalBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget), Category = "UI|Progress Bar")
	class UProgressBar* HealthBar;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget), Category = "UI|Images")
	class UImage* CharacterImage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI|Images")
	class UTexture2D* BackgroundTexture;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI|Images")
	class UTexture2D* FullTexture;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PlayerCharacter")
	class APMPlayerCharacter* PlayerCharacter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PlayerCharacter")
	class UPMHealthComponent* HealthComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Health")
	float CurrentHealth;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Health")
	float MaxHealth;
};
