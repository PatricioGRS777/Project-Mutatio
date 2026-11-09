

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "PMInteractionInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPMInteractionInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PROJECTMUTATIO_API IPMInteractionInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void Interact() = 0;
};
