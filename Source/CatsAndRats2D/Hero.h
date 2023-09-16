
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "InputActionValue.h"
#include "Public/Health/HealthComponent.h"

#include "Hero.generated.h"

class UInputMappingContext;
class UInputAction;

/**
 *
 */
UCLASS()
class CATSANDRATS2D_API AHero : public APaperZDCharacter
{
	GENERATED_BODY()

public:
	AHero();
	
	UPROPERTY(EditAnywhere, Category = Camera)
	USpringArmComponent *CameraBoom;

	UPROPERTY(EditAnywhere, Category = Camera)
	UCameraComponent *FollowCamera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	UHealthComponent *HealthComponent;


protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GameMode)
	UInputMappingContext *MappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
	UInputAction *MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
	UInputAction *RunAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
	UInputAction *JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
	UInputAction *DrwShtAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
	UInputAction *AttackAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
	UInputAction *InteractAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
	float MovementSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Input)
	int32 AttackState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
	float RunSpeedAddition;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool IsRunning;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool IsJumping;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool Rotate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool FacingFront;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool IsDrawn;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool CanDrwSht;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool CanAttack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
	bool IsMovementLocked;

	void Move(const FInputActionValue& Value);

	void Run(const FInputActionValue &Value);
	void StopRun(const FInputActionValue &Value);

	void CheckJump(const FInputActionValue &Value);

	void DrwSht(const FInputActionValue &Value);

	void Attack(const FInputActionValue &Value);
	
	void CheckForSpriteRotationChange();
	

public:
	
	
	
	virtual void Tick(float DeltaTime) override;

	void Interract();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
