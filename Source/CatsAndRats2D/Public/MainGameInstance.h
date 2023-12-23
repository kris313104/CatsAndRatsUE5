// Copyright © Krystian Burbano-Marek. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MainGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class CATSANDRATS2D_API UMainGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Score = 200;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CurrentHealth = 0;
};
