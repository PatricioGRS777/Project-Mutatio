

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PMGameInstance.generated.h"

/**
 * GameInstance is a class with persistent data throughout the lifetime of the game. It is not tied to any specific level or world.
 * It is a class that is initialized when the game starts and destroyed when the software is closed.
 */
UCLASS()
class PROJECTMUTATIO_API UPMGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
};
