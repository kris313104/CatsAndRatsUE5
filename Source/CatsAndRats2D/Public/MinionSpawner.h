// Copyright © Krystian Burbano-Marek. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "PaperFlipbookActor.h"
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
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> CubeClass;

	void SpawnMinion();

	bool IsPlayerClose();
	
};
