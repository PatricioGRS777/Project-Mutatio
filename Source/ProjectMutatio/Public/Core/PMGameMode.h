

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Data/PMGameState.h"
#include "PMGameMode.generated.h"

/**
 * GameMode defines how to play the game. It governs the game rules, scoring, what actors are allowed and how players enter the game.
 */
UCLASS()
class PROJECTMUTATIO_API APMGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	// Constructor for the GameMode class, wich is called when the game starts
	APMGameMode();
	
	void InitializeGame();

	virtual void BeginPlay();

	void MonsterToCapture();

	void GameOver();

	void RestartLevel();

	void Victory();

	void ExitMainMenu();

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Rules")
	int32 TotalMonsterCount = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Rules")
	int32 CapturedMonstersCount = 0;
	
};
