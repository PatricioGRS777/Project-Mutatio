

#pragma once
#include "Controllers/PMAIState.h"

UENUM(BlueprintType)
enum class EAIState : uint8
{
    EAI_None UMETA(DisplayName = "None"),
    EAI_Idle UMETA(DisplayName = "Idle"),
    EAI_Patrol UMETA(DisplayName = "Patrol"),
    EAI_Investigate UMETA(DisplayName = "Investigate"),
    EAI_Chase UMETA(DisplayName = "Chase"),
    EAI_Offensive UMETA(DisplayName = "Offensive"),
    EAI_Attack UMETA(DisplayName = "Attack"),
    EAI_Disguise UMETA(DisplayName = "Disguise"),
    EAI_Unconscious UMETA(DisplayName = "Unconscious")
};