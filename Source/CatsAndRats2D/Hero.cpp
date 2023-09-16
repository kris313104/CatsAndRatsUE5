// Fill out your copyright notice in the Description page of Project Settings.


#include "Hero.h"

#include "EngineUtils.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "MinionSpawner.h"
#include "PaperFlipbookComponent.h"
#include "PaperZDAnimationComponent.h"
#include "PaperZDAnimInstance.h"
#include "Components/InputComponent.h"
#include "GameFramework/PlayerController.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Health/HealthComponent.h"


AHero::AHero()
{
    PrimaryActorTick.bCanEverTick = true;

    //Camera and SpringArm configuration
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Boom"));
    
    if (CameraBoom)
    {
        CameraBoom->SetupAttachment(RootComponent);

        CameraBoom->TargetArmLength = 500.0f;
        //CameraBoom->SetRelativeRotation(FRotator(0.0f, 50.0f, 0.0f));

        FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Follow Camera"));
        if (FollowCamera)
        {
            FollowCamera->SetupAttachment(CameraBoom);
        }

    }

    HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));

    // Variable init
    AttackState = 0;
    CanAttack = true;
    IsRunning = false;
    IsJumping = false;
    Rotate = false;
    FacingFront = true;
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

            // Player actions
            EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AHero::Move);
            EnhancedInputComponent->BindAction(RunAction, ETriggerEvent::Started, this, &AHero::Run);
            EnhancedInputComponent->BindAction(RunAction, ETriggerEvent::Completed, this, &AHero::StopRun);
            EnhancedInputComponent->BindAction(DrwShtAction, ETriggerEvent::Started, this, &AHero::DrwSht);
            EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Started, this, &AHero::Attack);

            // Player interactions
            EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this, &AHero::Interract);
            
        }
}

void AHero::Move(const FInputActionValue& Value)
{
    if (!IsMovementLocked)
    {
        FVector2D DirectionValue = Value.Get<FVector2D>();
        DirectionValue.X *= MovementSpeed;
        DirectionValue.Y *= MovementSpeed;
        // UE_LOG(LogTemp, Log, TEXT("(X, Y) = (%f, %f)"), DirectionValue.X, DirectionValue.Y);
        if (Controller && (DirectionValue.X != 0.f))
        {
            FVector Forward = GetActorForwardVector();
            AddMovementInput(Forward, DirectionValue.X);

            if (DirectionValue.X < 0)
            {
                Rotate = true;
                
                // checkForSpriteRotationChange();
                //change sprite rotation to the left
                this->GetSprite()->SetRelativeRotation(FRotator(0.f, 180.f,0.f));
                
                if (DirectionValue.Y == 0.f || DirectionValue.Y == -0.f)
                {
                    FacingFront = true;
                }
                else 
                {
                    FacingFront = false;
                }
            }
                
            else
            {
                Rotate = false;
                // Change sprite rotation to the right
                this->GetSprite()->SetRelativeRotation(FRotator(0.f, 0, 0.f));
                if (DirectionValue.Y == 0.f || DirectionValue.Y == -0.f)
                {
                    FacingFront = true;
                }
                else
                {
                    FacingFront = false;
                }
            }
        }
        if (Controller && (DirectionValue.Y != 0.f))
        {
            FVector Sideways = GetActorRightVector();
            AddMovementInput(Sideways, -DirectionValue.Y);

            if (DirectionValue.Y < 0)
            {
                FacingFront = true;
            }
            else
            {
                FacingFront = false;
            }
            
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
    if (CanDrwSht)
    {
        if (IsDrawn)
        {
            
            GetAnimationComponent()->GetAnimInstance()->JumpToNode("Shiting");
            IsDrawn = false;
        }
        else
        {
            GetAnimationComponent()->GetAnimInstance()->JumpToNode("Drawing");
            IsDrawn = true;
        }
        CanDrwSht = false;
        GetCharacterMovement()->StopMovementImmediately();
        IsMovementLocked = true;
    }
    
}


void AHero::Attack(const FInputActionValue &Value)
{
    if (IsDrawn && CanAttack == true)
    {
        GetAnimationComponent()->GetAnimInstance()->JumpToNode("Attacking1");
        CanAttack = false;
    }
}

void AHero::CheckForSpriteRotationChange()
{
    if (Rotate)
    {
        GetSprite()->SetRelativeRotation(FRotator(0.f, 0.f ,180.f));
    }
    else
    {
        GetSprite()->SetRelativeRotation(FRotator(0.f, 0.f, 165.f));
        
    }
}

void AHero::Interract()
{
    UWorld* World = GetWorld();

    if (World)
    {
        TArray<AMinionSpawner*> MinionSpawners;;
        TActorIterator<AMinionSpawner> SpawnerIterator(World);
        while (SpawnerIterator)
        {
            AMinionSpawner *MinionSpawner = *SpawnerIterator;
            if (MinionSpawner)
            {
                MinionSpawners.Add(MinionSpawner);
            }
            ++SpawnerIterator;
        }
    }
}
