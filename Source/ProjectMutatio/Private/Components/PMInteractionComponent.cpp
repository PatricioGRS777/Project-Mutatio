#include "Components/PMInteractionComponent.h"
#include "LogMacros.h"
#include "LogVerbosity.h"

UPMInteractionComponent::UPMInteractionComponent(){
    PrimaryComponentTick.bCanEverTick = false; //disables per tick action to save performance
}

void UPMInteractionComponent::Interact(){
    //Debug
    UE_LOG(LogTemp, Log, TEXT("Interaction called!"));
}