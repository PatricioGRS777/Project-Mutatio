


#include "PMGameMode.h"
#include "PlayerController/PMPlayerController.h"
#include "Characters/Monsters/ShapeShifting/PMShapeShiftingCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"

APMGameMode::APMGameMode()
{
    UE_LOG(LogTemp, Warning, TEXT("APMGameMode::APMGameMode() GameMode initialized successfully."));

    InitializeGame();

}

void APMGameMode::InitializeGame()
{
    static ConstructorHelpers::FClassFinder<APawn> PlayerCharacterBPClass(TEXT("/Game/Characters/Humans/Prototype_Character/BP_PlayerCharacter"));

    if (!PlayerCharacterBPClass.Succeeded())
    {
        UE_LOG(LogTemp, Error, TEXT("APMGameMode::APMGameMode() Failed to find PlayerCharacter Blueprint class."));
    }

    // Integrate the PlayerControlle into the GameMode, allowing the player to control the character
    PlayerControllerClass = APMPlayerController::StaticClass();
    DefaultPawnClass = PlayerCharacterBPClass.Class;
}

void APMGameMode::BeginPlay()
{
    Super::BeginPlay();

    MonsterToCapture();
}

void APMGameMode::MonsterToCapture()
{
    if (UWorld* World = GetWorld())
    {
        for (TActorIterator<APMShapeShiftingCharacter> It(World); It; ++It)
        {
            TotalMonsterCount++;
        }
    }

    UE_LOG(LogTemp, Warning, TEXT("APMGameMode::MonsterToCapture() %i"), TotalMonsterCount);

}

void APMGameMode::GameOver()
{
    UE_LOG(LogTemp, Error, TEXT("APMGameMode::GameOver() Game Over."));

}


void APMGameMode::RestartLevel()
{    
    if (!GetWorld())
    {
        UE_LOG(LogTemp, Error, TEXT("APMGameMode::RestartLevel() UWorld is not valid."));
        return;
    }

    ULevel* CurrentLevel = GetLevel();

    if (!CurrentLevel)
    {
        return;
    }

    FName LevelName = CurrentLevel->GetFName();

    UGameplayStatics::OpenLevel(GetWorld(), LevelName);
}

void APMGameMode::Victory()
{
    if (CapturedMonstersCount >= TotalMonsterCount)
    {
        UE_LOG(LogTemp, Warning, TEXT("APMGameMode::Victory() Victory."));  
    }
}

void APMGameMode::ExitMainMenu()
{

}