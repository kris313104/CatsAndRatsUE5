// Copyright © Krystian Burbano-Marek. All rights reserved.


#include "..\Public\Minion.h"

#include "PaperFlipbookComponent.h"
#include "PaperZDAnimationComponent.h"

AMinion::AMinion()
{
	SensingComponent = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("Pawn Sensing Component"));
}

void AMinion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UPaperFlipbookComponent* FlipbookComponent = GetSprite();

	if (_PawnVelocity.X > 0)
	{
		_IsMoving = true;

		if (FlipbookComponent)
		{
			FlipbookComponent->SetWorldRotation(FRotator(0.f, 180.f, 0.f));
		}
	}

	else if (_PawnVelocity.X < 0)
	{
		_IsMoving = true;

		if (FlipbookComponent)
		{
			FlipbookComponent->SetWorldRotation(FRotator(0.f, 0.f, 0.f));
		}
	}

	else if(_PawnVelocity.Y != 0)
	{
		_IsMoving = true;
	}

	else
	{
		_IsMoving = false;
	}
}
