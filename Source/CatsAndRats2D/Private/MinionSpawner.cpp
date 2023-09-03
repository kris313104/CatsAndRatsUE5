// Copyright © Krystian Burbano-Marek. All rights reserved.


#include "MinionSpawner.h"

#define CLOSE_DISTANCE 100.0f

AMinionSpawner::AMinionSpawner()
{
	
}


void AMinionSpawner::BeginPlay()
{
	Super::BeginPlay();

	
	if (InputComponent)
	{
		InputComponent->BindKey(this, &AMinionSpawner::SpawnMinion, EKeys::F);
		// InputComponent->BindAction("spawnminion", IE_Pressed, this, &AMinionSpawner::SpawnMinion);
	}
	
}

void AMinionSpawner::SpawnMinion()
{
	if (IsPlayerClose())
	{
		UWorld* World = GetWorld();
		if (World)
		{
			World->SpawnActor<AActor>(CubeClass, GetActorLocation(), GetActorRotation());
		}
	}
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




