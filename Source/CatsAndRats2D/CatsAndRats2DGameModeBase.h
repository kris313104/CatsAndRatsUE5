// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CatsAndRats2DGameModeBase.generated.h"

/**
 *
 */
UCLASS()
class CATSANDRATS2D_API ACatsAndRats2DGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	ACatsAndRats2DGameModeBase();

	UFUNCTION(BlueprintCallable)
	bool GetNextAttack();

	UFUNCTION(BlueprintCallable)
	void SetNextAttack(bool _NextAttack);

	UFUNCTION(BlueprintCallable)
	int GetAttackState();

	UFUNCTION(BlueprintCallable)
	void SetAttackState(int _AttackState);

	UFUNCTION(BlueprintCallable)
	bool GetTransitionToNextAttack();

	UFUNCTION(BlueprintCallable)
	void SetTransitionToNextAttack(bool _TransitionToNextAttack);

private:
	int AttackState;

	bool NextAttack;

	bool TransitionToNextAttack;
};
