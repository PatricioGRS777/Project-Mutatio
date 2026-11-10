


#include "PMGuardCharacter.h"

APMGuardCharacter::APMGuardCharacter()
{
    static ConstructorHelpers::FClassFinder<UAnimInstance>
        GuardABPClass(TEXT("/Game/Animations/Animation_Blueprints/Characters/Humans/Guards/ABP_Guard"));

    if (!GuardABPClass.Succeeded())
    {
        UE_LOG(LogTemp, Error, TEXT("APMGuardCharacter::APMGuardCharacter() Animatiom Blueprint is null."));
        return;
    }

    GetMesh()->SetAnimInstanceClass(GuardABPClass.Class);
}

void APMGuardCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void APMGuardCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}