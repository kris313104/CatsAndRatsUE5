// Copyright © Krystian Burbano-Marek. All rights reserved.


#include "MinionSpawner.h"

#include "GameFramework/InputSettings.h"
#include "InputCoreTypes.h"

AMinionSpawner::AMinionSpawner()
{
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	InteractingBox = CreateDefaultSubobject<UBoxComponent>(TEXT("InteractBox"));

	
	CollisionBox->SetupAttachment(RootComponent);
	InteractingBox->SetupAttachment(RootComponent);
}


void AMinionSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

AActor* AMinionSpawner::SpawnMinion()
{
	const APawn* Hero = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (Hero != nullptr && InteractingBox->IsOverlappingActor(Hero))
	{
		UWorld* World = GetWorld();
		if (World)
		{
			
			FVector ActorLocation = Hero->GetActorLocation();
			
			AActor* SpawnedMinion = World->SpawnActor<AActor>(MinionClass, ActorLocation, GetActorRotation());
			
			return SpawnedMinion;
			
		}
		
	}
	return nullptr;
	
}




