

#pragma once

#include "Data/PMGameState.h"

UENUM(BlueprintType)
enum class EGameState : uint8
{
    EGS_None UMETA(DisplayName = "None"),
    EGS_Playing UMETA(DisplayName = "Playing"),
    EGS_Pause UMETA(DisplayName = "Pause"),
    EGS_Caught UMETA(DisplayName = "Caught"),
    EGS_Spotted UMETA(DisplayName = "Spotted"),
    EGS_GameOver UMETA(DisplayName = "Game Over"),
    EGS_Victory UMETA(DisplayName = "Victory")
};