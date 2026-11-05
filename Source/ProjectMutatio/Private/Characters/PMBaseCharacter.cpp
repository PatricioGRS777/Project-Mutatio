


#include "PMBaseCharacter.h"
#include "Components/CapsuleComponent.h"

// Sets default values
APMBaseCharacter::APMBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> DefaultMesh(TEXT("/Game/Meshes/Skeletal_Meshes/Characters/Humans/Prototype_Character/SKM_Mannequin.SKM_Mannequin"));

    if (DefaultMesh.Succeeded())
    {
        GetMesh()->SetSkeletalMesh(DefaultMesh.Object);
    }

	// Set the capsule component collision to all characters
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
	GetCapsuleComponent()->SetCapsuleSize(42.0f, 96.0f);

    GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -96.0f));
	GetMesh()->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));


}

// Called when the game starts or when spawned
void APMBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APMBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APMBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

