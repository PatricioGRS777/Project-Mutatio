

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PMDisguisePositionActor.generated.h"

UCLASS()
class PROJECTMUTATIO_API APMDisguisePositionActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APMDisguisePositionActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
