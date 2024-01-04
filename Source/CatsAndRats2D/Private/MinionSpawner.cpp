// Copyright © Krystian Burbano-Marek. All rights reserved.


#include "MinionSpawner.h"

#include "GameFramework/InputSettings.h"
#include "InputCoreTypes.h"
#include "MainGameInstance.h"
#include "CatsAndRats2D/CatsAndRats2DGameModeBase.h"
#include "Kismet/GameplayStatics.h"

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
			ACatsAndRats2DGameModeBase* GameMode = Cast<ACatsAndRats2DGameModeBase>(UGameplayStatics::GetGameMode(World));

			if (GameMode)
			{
				if (GameMode->GetCurrentScore() >= 100)
				{
					GameMode->AddScore(-100);
					GameMode->UpdateScoreOnScreen();
					UMainGameInstance* GameInstance = Cast<UMainGameInstance>(GetGameInstance());
					GameInstance->PlayerCurrentMinions++;
					
					FVector ActorLocation = Hero->GetActorLocation();
			
					AActor* SpawnedMinion = World->SpawnActor<AActor>(MinionClass, ActorLocation, GetActorRotation());
			
					return SpawnedMinion;
				}
			}
			
			
		}
		
	}
	return nullptr;
	
}




