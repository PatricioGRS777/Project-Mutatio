

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PMCaptureBarWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTMUTATIO_API UPMCaptureBarWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	virtual void NativeTick(const FGeometry& Geometry, float DeltaTime);

	void InitializeVariables();

	void SetprogressBar(class UProgressBar* NewProgressBar, class UTexture2D* EmptyTexture, class UTexture2D* FullTexture);

	void UpdateProgressBar();

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget), Category = "UI|Vertica lBox")
	class UVerticalBox* CaptureVerticalBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget), Category = "UI|Images")
	class UProgressBar* CaptureBar;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget), Category = "UI|Images")
	class UImage* ButtonImage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI|Material")
	class UMaterialInterface* ButtonMaterial;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI|Material")
	class UMaterialInstanceDynamic* ButtonMaterialDynamic;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI|Textures")
	class UTexture2D* BackgroundTexture;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI|Textures")
	class UTexture2D* FillTexture;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player Character")
	class APMPlayerCharacter* PlayerCharacter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player Character")
	class UPMSoulVacuumComponent* VacuumComponent;

};
