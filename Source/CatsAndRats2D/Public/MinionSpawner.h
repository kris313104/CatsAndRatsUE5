// Copyright © Krystian Burbano-Marek. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "PaperFlipbookActor.h"
#include "CatsAndRats2D/Hero.h"
#include "MinionSpawner.generated.h"

/**
 * 
 */
UCLASS()
class CATSANDRATS2D_API AMinionSpawner : public APaperFlipbookActor
{
	GENERATED_BODY()
public:
	AMinionSpawner();
protected:
	virtual void BeginPlay() override;
	
private:
	const FKey INTERACT_KEY = EKeys::F;
	const float CLOSE_DISTANCE = 100.f;
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> CubeClass;
	
	void SpawnMinion();

	bool IsPlayerClose();
	
};
