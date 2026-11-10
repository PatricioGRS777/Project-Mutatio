

#pragma once

#include "CoreMinimal.h"
#include "Characters/Humans/PMHumanCharacter.h"
#include "PMGuardCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTMUTATIO_API APMGuardCharacter : public APMHumanCharacter
{
	GENERATED_BODY()

public:

	APMGuardCharacter();
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;	
};
