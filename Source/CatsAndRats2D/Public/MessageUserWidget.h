// Copyright © Krystian Burbano-Marek. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MessageUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class CATSANDRATS2D_API UMessageUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FString Message = FString("");

	
	void SetMessage(FString _message);
};
