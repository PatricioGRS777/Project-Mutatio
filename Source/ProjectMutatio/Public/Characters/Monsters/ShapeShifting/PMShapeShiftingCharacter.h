

#pragma once

#include "CoreMinimal.h"
#include "Characters/Monsters/PMMonsterCharacter.h"
#include "PMShapeShiftingCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTMUTATIO_API APMShapeShiftingCharacter : public APMMonsterCharacter
{
	GENERATED_BODY()

public:

	APMShapeShiftingCharacter();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
};
