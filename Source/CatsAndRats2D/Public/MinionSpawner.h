// Copyright © Krystian Burbano-Marek. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Minion.h"
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
	
	void SpawnMinion();
protected:
	virtual void BeginPlay() override;
	
private:
	const FKey INTERACT_KEY = EKeys::F;
	const float CLOSE_DISTANCE = 100.f;
	UPROPERTY(EditAnywhere)
	TSubclassOf<AMinion> MinionClass;
	
	bool IsPlayerClose();
	
};
