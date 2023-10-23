// Copyright © Krystian Burbano-Marek. All rights reserved.


#include "MinionSpawner.h"

#include "GameFramework/InputSettings.h"
#include "InputCoreTypes.h"

AMinionSpawner::AMinionSpawner()
{
	// empty
}


void AMinionSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMinionSpawner::SpawnMinion()
{
	if (IsPlayerClose())
	{
		UWorld* World = GetWorld();
		if (World)
		{
			// Temp cube mesh replacing the spawned minion. For testing
			
			
			AActor* SpawnedMinion = World->SpawnActor<AActor>(MinionClass, GetActorLocation(), GetActorRotation());
			
			
		}
		UE_LOG(LogTemp, Warning, TEXT("Spawning minion"));
	}
	UE_LOG(LogTemp, Warning, TEXT("SpawnMinion() call inside minion spawner class"));
}

bool AMinionSpawner::IsPlayerClose()
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (PlayerController)
	{
		FVector PlayerLocation = PlayerController->GetPawn()->GetActorLocation();
		float Distance = FVector::Distance(PlayerLocation, GetActorLocation());
		
		return Distance < CLOSE_DISTANCE;
	}
	return false;
}




