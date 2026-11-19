


#include "PMPatrolPointActor.h"

// Sets default values
APMPatrolPointActor::APMPatrolPointActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UE_LOG(LogTemp, Warning, TEXT("APMPatrolPointActor::APMPatrolPointActor() PatrolPointActor initialized succesfully."));

}

// Called when the game starts or when spawned
void APMPatrolPointActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APMPatrolPointActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

