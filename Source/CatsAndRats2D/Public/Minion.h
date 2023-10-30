// Copyright © Krystian Burbano-Marek. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "PaperFlipbookActor.h"
#include "PaperZDCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Perception/PawnSensingComponent.h"
#include "Minion.generated.h"

/**
 * 
 */
UCLASS()
class CATSANDRATS2D_API AMinion : public APaperZDCharacter
{
	GENERATED_BODY()

public:
	AMinion();


	UPROPERTY(EditAnywhere, Category="AI")
	UPawnSensingComponent* SensingComponent;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly)
	bool GetIsMoving() const { return _IsMoving; }

	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly)
	void SetIsMoving(const bool IsMoving){ _IsMoving = IsMoving; }

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly)
	FVector GetPawnVelocity() const { return _PawnVelocity; }

	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly)
	void SetPawnVelocity(const FVector PawnVelocity) { _PawnVelocity = PawnVelocity; }
	
	virtual void Tick(float DeltaTime) override;
private:
	bool _IsMoving;

	FVector _PawnVelocity;
};
