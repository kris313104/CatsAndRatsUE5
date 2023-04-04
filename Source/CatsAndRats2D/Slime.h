// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"

#include "Public/Health/HealthComponent.h"

#include "Slime.generated.h"

class UPaperFlipbookComponent;
class UPawnSensingComponent;
/**
 *
 */
UCLASS()
class CATSANDRATS2D_API ASlime : public APaperZDCharacter
{
	GENERATED_BODY()

public:
	ASlime();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = AI)
	UPawnSensingComponent *SensingComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	UHealthComponent *HealthComponent;


	UFUNCTION(BlueprintCallable)
	void SetIsMoving(bool _IsMoving);

	UFUNCTION(BlueprintCallable)
	bool GetIsMoving();

	virtual void Tick(float DeltaTime) override;
private:
	bool IsMoving;

	bool Rotate;

	APawn *MyPawn;

	FVector PawnVelocity;

	UPaperFlipbookComponent *SpriteComponent;

};
