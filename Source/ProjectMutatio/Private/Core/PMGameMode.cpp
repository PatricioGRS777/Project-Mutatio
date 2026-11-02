


#include "PMGameMode.h"
#include "PlayerController/PMPlayerController.h"

APMGameMode::APMGameMode()
{
    UE_LOG(LogTemp, Warning, TEXT("APMGameMode::APMGameMode() GameMode initialized successfully."));

    // Integrate the PlayerControlle into the GameMode, allowing the player to control the character
    PlayerControllerClass = APMPlayerController::StaticClass();
}