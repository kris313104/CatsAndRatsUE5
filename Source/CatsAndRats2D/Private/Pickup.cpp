#include "Pickup.h"
#include "../Hero.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/PrimitiveComponent.h"
#include "Engine/DamageEvents.h"
#include "PaperFlipbookComponent.h"


// Sets default values
APickup::APickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Amount = 1;

	PickupRoot = CreateDefaultSubobject<USceneComponent>(TEXT("PickupRoot"));

	if (PickupRoot)
	{
	PickupRoot->SetupAttachment(RootComponent);
	RootComponent = PickupRoot;
	}

	FlipbookComponent = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("FlipbookComponent"));
	if (FlipbookComponent)
	{
	FlipbookComponent->AttachToComponent(PickupRoot, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	}

	PickupBox = CreateDefaultSubobject<UBoxComponent>(TEXT("PickupBox"));
	if (PickupBox)
	{
	PickupBox->SetWorldScale3D(FVector(1.f, 1.f, 1.f));
	PickupBox->AttachToComponent(PickupRoot, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	}
}

// Called when the game starts or when spawned
void APickup::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

