


#include "PMShapeShiftingCharacter.h"

APMShapeShiftingCharacter::APMShapeShiftingCharacter()
{
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