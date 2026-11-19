


#include "PMGuardCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "AIController.h"

APMGuardCharacter::APMGuardCharacter()
{
    static ConstructorHelpers::FClassFinder<AAIController>
        GuardAICAsset(TEXT("/Game/Controllers/Humans/Guard/AIC_Guard"));

    if (!GuardAICAsset.Succeeded())
    {
        UE_LOG(LogTemp, Error, TEXT("APMGuardCharacter::APMGuardCharacter() AIController is null"));
        return;
    }

    AIControllerClass = GuardAICAsset.Class;

    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

    static ConstructorHelpers::FClassFinder<UAnimInstance>
        GuardABPClass(TEXT("/Game/Animations/Animation_Blueprints/Characters/Humans/Guards/ABP_Guard"));

    if (!GuardABPClass.Succeeded())
    {
        UE_LOG(LogTemp, Error, TEXT("APMGuardCharacter::APMGuardCharacter() Animatiom Blueprint is null."));
        return;
    }

    GetMesh()->SetAnimInstanceClass(GuardABPClass.Class);

    GetCharacterMovement()->MaxWalkSpeed = 150.0f;
}

void APMGuardCharacter::BeginPlay()
{
    Super::BeginPlay();

}

void APMGuardCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}
