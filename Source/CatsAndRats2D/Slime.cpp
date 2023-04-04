// Fill out your copyright notice in the Description page of Project Settings.


#include "Slime.h"
#include "GameFramework/Pawn.h"
#include "PaperFlipbookComponent.h"
#include "PaperCharacter.h"
#include "Perception/PawnSensingComponent.h"

ASlime::ASlime()
{
    PrimaryActorTick.bCanEverTick = true;

    SensingComponent = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("Sensing Component"));

    HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));


    IsMoving = false;
    Rotate = false;

    MyPawn = Cast<APawn>(this);

    APaperCharacter* MyPaperCharacter = Cast<APaperCharacter>(this);

    SpriteComponent = Cast<UPaperFlipbookComponent>(MyPaperCharacter->FindComponentByClass<UPaperFlipbookComponent>());
}

void ASlime::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    PawnVelocity = MyPawn->GetVelocity();

    if (PawnVelocity.X > 0)
    {
        IsMoving = true;
        Rotate = true;
        if(SpriteComponent)
        {
        SpriteComponent->SetWorldRotation(FRotator(0.f, 180.f, 0.f));
        }
    }
    else if (PawnVelocity.X < 0)
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

void ASlime::SetIsMoving(bool _IsMoving)
{
    IsMoving = _IsMoving;
}


bool ASlime::GetIsMoving()
{
    return IsMoving;
}
