

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PMPlayerController.generated.h"

/**
 * The PlayerController serves as the communication bridge between a human player and the character object.
 * It is responsible for receiving input from the player and translating it into actions for the character to perform.
 */
UCLASS()
class PROJECTMUTATIO_API APMPlayerController : public APlayerController
{
	GENERATED_BODY()
	
};
