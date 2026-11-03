


#include "PMGameMode.h"
#include "PlayerController/PMPlayerController.h"

APMGameMode::APMGameMode()
{
    UE_LOG(LogTemp, Warning, TEXT("APMGameMode::APMGameMode() GameMode initialized successfully."));

    static ConstructorHelpers::FClassFinder<APawn> PlayerCharacterBPClass(TEXT("/Game/Characters/Humans/Player_Character/BP_PlayerCharacter"));

    if (!PlayerCharacterBPClass.Succeeded())
    {
        UE_LOG(LogTemp, Error, TEXT("APMGameMode::APMGameMode() Failed to find PlayerCharacter Blueprint class."));
    }

    // Integrate the PlayerControlle into the GameMode, allowing the player to control the character
    PlayerControllerClass = APMPlayerController::StaticClass();
    DefaultPawnClass = PlayerCharacterBPClass.Class;

}