

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PMSoulVacuumComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTMUTATIO_API UPMSoulVacuumComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPMSoulVacuumComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void InitializeVariables();

	void UpdateAimRotation(float DeltaTime);

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player Character")
	class APMPlayerCharacter* PlayerCharacter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player Character")
	class APMPlayerController* PlayerController;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player Character")
	float AimRotationSpeed = 279.0f;

		
};
