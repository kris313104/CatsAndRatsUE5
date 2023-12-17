
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "InputActionValue.h"
// #include "Components/PointLightComponent.h"
#include "MessageUserWidget.h"
#include "Public/Health/HealthComponent.h"

#include "Hero.generated.h"

class UPointLightComponent;
class UInputMappingContext;
class UInputAction;
class UMessageUserWidget;

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

	UPROPERTY(EditAnywhere, Category = Light)
	UPointLightComponent *FrontPointLightComponent;

	// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Light)
	// UPointLightComponent *BackPointLightComponent;

	UPROPERTY(EditAnywhere, Category = Light)
	USpringArmComponent *LightArm;

	UFUNCTION(BlueprintCallable)
	void AttackWithMinions(AActor *AttackedActor, bool Attack);

	UFUNCTION(BlueprintCallable)
	void MoveMinionsToLocation(FVector MovingLocation);

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

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UMessageUserWidget *InteractMessageWidget;
	
	
	void Move(const FInputActionValue& Value);

	void Run(const FInputActionValue &Value);
	void StopRun(const FInputActionValue &Value);

	void CheckJump(const FInputActionValue &Value);

	void DrwSht(const FInputActionValue &Value);

	void Attack(const FInputActionValue &Value);
	
	void CheckForSpriteRotationChange();

public:
	virtual void NotifyActorOnClicked(FKey ButtonPressed) override;


	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintPure, BlueprintCallable)
	AActor* GetSelectedEnemyActor() const { return SelectedEnemy; }
	
	void Interact();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly)
	TArray<APawn*> GetCurrentMinions() const { return CurrentMinions; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	UMessageUserWidget* GetMessageUserWidget() const { return InteractMessageWidget; }
	UFUNCTION(BlueprintCallable)
	void SetMessageUserWidget(UMessageUserWidget* _messageUserWidget) { InteractMessageWidget = _messageUserWidget; }
	
	
private:
	APlayerController *PlayerController;

	AActor *SelectedEnemy;

	TArray<APawn*> CurrentMinions;
};
