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

void AMinionSpawner::SpawnMinion()
{
	const APawn* Hero = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (Hero != nullptr && InteractingBox->IsOverlappingActor(Hero))
	{
		UWorld* World = GetWorld();
		if (World)
		{
			// Temp cube mesh replacing the spawned minion. For testing
			
			FVector ActorLocation = Hero->GetActorLocation();
			// ActorLocation = FVector(ActorLocation.X, ActorLocation.Y, ActorLocation.Z);
			AActor* SpawnedMinion = World->SpawnActor<AActor>(MinionClass, ActorLocation, GetActorRotation());
			
			
		}
		UE_LOG(LogTemp, Warning, TEXT("Spawning minion"));
	}
	UE_LOG(LogTemp, Warning, TEXT("SpawnMinion() call inside minion spawner class"));
}




