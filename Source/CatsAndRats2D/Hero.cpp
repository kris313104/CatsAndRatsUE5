// Fill out your copyright notice in the Description page of Project Settings.


#include "Hero.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/PlayerController.h"
#include "InputMappingContext.h"



AHero::AHero()
{
    PrimaryActorTick.bCanEverTick = true;

    //Camera and SpringArm configuration
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Boom"));
	CameraBoom->SetupAttachment(RootComponent);

	CameraBoom->TargetArmLength = 500.0f;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Follow Camera"));
	FollowCamera->SetupAttachment(CameraBoom);

    HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));


    AttackState = 0;
    CanAttack = true;
    IsRunning = false;
    IsJumping = false;
    Rotate = false;
    IsDrawn = false;
    CanDrwSht = true;
    IsMovementLocked = false;

}

void AHero::BeginPlay()
{
    Super::BeginPlay();

    // Add Input Mapping Context
    APlayerController *PlayerController = Cast<APlayerController>(GetController());
    if (PlayerController)
    {
        UEnhancedInputLocalPlayerSubsystem *Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
        if (Subsystem)
        {
            Subsystem->AddMappingContext(MappingContext, 0);
        }
    }
}

void AHero::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);



    if (IsJumping)
    {
        Jump();
    }
}

void AHero::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
        Super::SetupPlayerInputComponent(PlayerInputComponent);

        if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
        {
        EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AHero::Move);
        EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &AHero::CheckJump);
        EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &AHero::CheckJump);
        EnhancedInputComponent->BindAction(RunAction, ETriggerEvent::Started, this, &AHero::Run);
        EnhancedInputComponent->BindAction(RunAction, ETriggerEvent::Completed, this, &AHero::StopRun);
        EnhancedInputComponent->BindAction(DrwShtAction, ETriggerEvent::Started, this, &AHero::DrwSht);
        EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Started, this, &AHero::Attack);
        }
}

void AHero::Move(const FInputActionValue& Value)
{
    if (!IsMovementLocked)
    {
        FVector2D DirectionValue = Value.Get<FVector2D>();
        DirectionValue.X *= MovementSpeed;
        DirectionValue.Y *= MovementSpeed;

        if (Controller && (DirectionValue.X != 0.f))
        {
            FVector Forward = GetActorForwardVector();
            AddMovementInput(Forward, DirectionValue.X);

            if (DirectionValue.X < 0)
                Rotate = true;
            else
                Rotate = false;
        }
        if (Controller && (DirectionValue.Y != 0.f))
        {
            FVector Sideways = GetActorRightVector();
            AddMovementInput(Sideways, -DirectionValue.Y);
        }
    }

}

void AHero::Run(const FInputActionValue &Value)
{
    IsRunning = Value.Get<bool>();
    if (IsRunning)
    {
        MovementSpeed += RunSpeedAddition;
    }
}

void AHero::StopRun(const FInputActionValue &Value)
{
    IsRunning = Value.Get<bool>();
    if (!IsRunning)
    {
        MovementSpeed -= RunSpeedAddition;
    }
}


void AHero::CheckJump(const FInputActionValue &Value)
{
    if (IsJumping)
        IsJumping = false;
    else
        IsJumping = true;
}


void AHero::DrwSht(const FInputActionValue &Value)
{

    if(!(AttackState > 1))
    {
        CanDrwSht = true;
    }
    else
    {
        CanDrwSht = false;
    }

    if(CanDrwSht)
    {
        if(IsDrawn)
        {
            CanDrwSht = false;
            IsDrawn = false;
        }
        else
        {
            CanDrwSht = false;
            IsDrawn = true;
        }
    }
}


void AHero::Attack(const FInputActionValue &Value)
{

}
