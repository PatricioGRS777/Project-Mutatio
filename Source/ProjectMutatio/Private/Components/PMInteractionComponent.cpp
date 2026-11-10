#include "Components/PMInteractionComponent.h"
#include "PMInteractionInterface.h"

UPMInteractionComponent::UPMInteractionComponent(){
    PrimaryComponentTick.bCanEverTick = false; //disables per tick action to save performance
}

void UPMInteractionComponent::Interact(){
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
    if (!bHit) {
        return;
    }

    IPMInteractionInterface* Target = Cast<IPMInteractionInterface>(Hit.GetActor());
    if (Target) {
        Target->Interact();
    }
}
