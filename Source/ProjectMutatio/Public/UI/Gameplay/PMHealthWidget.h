

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

	void UpdateHealthBar();

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget), Category = "UI|Progress Bar")
	class UHorizontalBox* HealthHorizontalBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget), Category = "UI|Progress Bar")
	class UProgressBar* HealthBar;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget), Category = "UI|Images")
	class UImage* CharacterImage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI|Images")
	class UImage* EmptyHealthImage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI|Images")
	class UImage* FullHealthImage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PlayerCharacter")
	class APMPlayerCharacter* PlayerCharacter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PlayerCharacter")
	class UPMHealthComponent* HealthComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Health")
	float CurrentHealth;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Health")
	float MaxHealth;
};
