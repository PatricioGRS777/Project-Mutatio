


#include "PMShapeShiftingCharacter.h"
#include "AIController.h"

APMShapeShiftingCharacter::APMShapeShiftingCharacter()
{
    static ConstructorHelpers::FClassFinder<AAIController>
        ShiftingAICAsset(TEXT("/Game/Controllers/Monsters/Shape_Shifting/AIC_ShapeShifting"));

    if (!ShiftingAICAsset.Succeeded())
    {
        UE_LOG(LogTemp, Error, TEXT("APMShapeShiftingCharacter::APMShapeShiftingCharacter() ShiftingAICAsset is null."));
        return;
    }

    AIControllerClass = ShiftingAICAsset.Class;

    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

    static ConstructorHelpers::FClassFinder<UAnimInstance>
        ShapeShiftingBPClass(TEXT("/Game/Animations/Animation_Blueprints/Characters/Monsters/Shape_Shifting/ABP_ShapeShifting"));

    if (!ShapeShiftingBPClass.Succeeded())
    {
        UE_LOG(LogTemp, Error, TEXT("APMShapeShiftingCharacter::APMShapeShiftingCharacter() AnimationBlueprint class is null."));
        return;
    }

    GetMesh()->SetAnimInstanceClass(ShapeShiftingBPClass.Class);
}

void APMShapeShiftingCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void APMShapeShiftingCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}