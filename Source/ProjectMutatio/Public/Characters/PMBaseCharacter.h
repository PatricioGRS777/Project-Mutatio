

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PMBaseCharacter.generated.h"

class UPMHealthComponent;

/**
 * The BaseCharacter class serves as the foundation for all character types in the game. 
 * It provides essential functionality and properties that are common to all characters, 
 * such as states, movements and interaction with the game world
 */

UCLASS()
class PROJECTMUTATIO_API APMBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APMBaseCharacter();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UPMHealthComponent* HealthComponent;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
