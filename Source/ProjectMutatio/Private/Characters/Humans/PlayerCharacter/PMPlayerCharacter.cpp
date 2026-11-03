


#include "PMPlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

APMPlayerCharacter::APMPlayerCharacter()
{
    // Create the default subobject for the components
    SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm Component"));
    CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));

    SpringArmComp->SetupAttachment(GetRootComponent());
    CameraComp->SetupAttachment(SpringArmComp);

    SpringArmComp->SetRelativeRotation(FRotator(-35.0f, 0.0f, 0.0f));

    // This set the desire distance of the camera from the player character
    SpringArmComp->TargetArmLength = 1200.0f;

}