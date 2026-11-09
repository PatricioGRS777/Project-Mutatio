#include "Components/PMInteractionComponent.h"
#include "LogMacros.h"
#include "LogVerbosity.h"
#include "PMInteractionInterface.h"

UPMInteractionComponent::UPMInteractionComponent(){
    PrimaryComponentTick.bCanEverTick = false; //disables per tick action to save performance
}

void UPMInteractionComponent::Interact(){
    // DEBUG
    UE_LOG(LogTemp, Log, TEXT("Interaction called!"));

    // find the target
    AActor* Owner = GetOwner();
    if (!Owner) {
        return;
    }

    FVector Start = Owner->GetActorLocation();
    FVector End = Start + Owner->GetActorForwardVector() * 250.0f;

    FCollisionQueryParams QueryParams;
    QueryParams.AddIgnoredActor(Owner);

    FHitResult Hit;
    bool bHit = GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, QueryParams);
    if (bHit) {
        UE_LOG(LogTemp, Log, TEXT("Interaction hit: %s"), *GetNameSafe(Hit.GetActor()));
    }
    
    IPMInteractionInterface* Target = Cast<IPMInteractionInterface>(Hit.GetActor());     //cast to make sure it's fine
    if (Target) {
        Target->Interact();
    }
    else {
        UE_LOG(LogTemp, Log, TEXT("Interact Interface not implement!"), *GetNameSafe(Hit.GetActor()));
    }
}