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

	UFUNCTION(BlueprintPure)
	bool GetIsMoving() const { return IsMoving; }

	UFUNCTION(BlueprintCallable)
	void SetIsMoving(const bool _IsMoving){ IsMoving = _IsMoving; }

	UFUNCTION(BlueprintPure)
	FVector GetPawnVelocity() const { return PawnVelocity; }

	UFUNCTION(BlueprintCallable)
	void SetPawnVelocity(const FVector _PawnVelocity) { PawnVelocity = _PawnVelocity; }

	UFUNCTION(BlueprintPure)
	bool GetRotate() const { return Rotate; }

	UFUNCTION(BlueprintCallable)
	void SetRotate(const bool _Rotate) { Rotate = _Rotate; }

	
	
	virtual void Tick(float DeltaTime) override;
private:
	bool IsMoving;

	bool Rotate;

	UPaperFlipbookComponent* SpriteComponent;
	
	FVector PawnVelocity;
};
