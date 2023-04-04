// Copyright Epic Games, Inc. All Rights Reserved.
#include "CatsAndRats2DGameModeBase.h"
#include "Hero.h"


ACatsAndRats2DGameModeBase::ACatsAndRats2DGameModeBase()
{
    PrimaryActorTick.bCanEverTick = false;
    PrimaryActorTick.bStartWithTickEnabled = false;
    PrimaryActorTick.bAllowTickOnDedicatedServer = false;

    AttackState = 0;
    NextAttack = false;
    TransitionToNextAttack = false;
}

int ACatsAndRats2DGameModeBase::GetAttackState()
{
    return AttackState;
}

void ACatsAndRats2DGameModeBase::SetAttackState(int _AttackState)
{
    this->AttackState = _AttackState;
}

bool ACatsAndRats2DGameModeBase::GetNextAttack()
{
    return NextAttack;
}

void ACatsAndRats2DGameModeBase::SetNextAttack(bool _NextAttack)
{
    this->NextAttack = _NextAttack;
}


void ACatsAndRats2DGameModeBase::SetTransitionToNextAttack(bool _TransitionToNextAttack)
{
    this->TransitionToNextAttack = _TransitionToNextAttack;
}

bool ACatsAndRats2DGameModeBase::GetTransitionToNextAttack()
{
    return TransitionToNextAttack;
}
