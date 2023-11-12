// Copyright © Krystian Burbano-Marek. All rights reserved.


#include "..\Public\Minion.h"

#include "PaperFlipbookComponent.h"
#include "PaperZDAnimationComponent.h"

AMinion::AMinion()
{
	PrimaryActorTick.bCanEverTick = true;
	SensingComponent = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("Pawn Sensing Component"));
	SpriteComponent = GetSprite();
}

void AMinion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	PawnVelocity = this->GetVelocity();
	
	
	if (PawnVelocity.X < 0)
	{
		IsMoving = true;
		Rotate = true;
		if(SpriteComponent)
		{
			SpriteComponent->SetWorldRotation(FRotator(0.f, 180.f, 0.f));
		}
	}
	else if (PawnVelocity.X > 0)
	{
		IsMoving = true;
		Rotate = false;
		SpriteComponent->SetWorldRotation(FRotator(0.f, 0.f, 0.f));
	}
	else if (PawnVelocity.Y != 0)
	{
		IsMoving = true;
	}
	else
	{
		IsMoving = false;
	}
}
