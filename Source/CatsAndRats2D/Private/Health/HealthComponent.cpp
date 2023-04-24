// Fill out your copyright notice in the Description page of Project Settings.


#include "Health/HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	//! Default health should be h(x)=4*x
	MaxHealth = 0;
	CurrentHealth = MaxHealth;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	AActor *Owner = GetOwner();
	if (Owner)
	{
		Owner->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::TakeDamage);
	}
}

void UHealthComponent::TakeDamage(AActor * DamagedActor, float Damage, const class UDamageType * DamageType, class AController * InstigatedBy, AActor * DamageCauser)
{
	CurrentHealth = FMath::Clamp(CurrentHealth - Damage, 0, MaxHealth);
}

// int UHealthComponent::GetCurrentHealth()
// {
// 	return CurrentHealth;
// }

// void UHealthComponent::SetCurrentHealth(int _CurrentHealth)
// {
// 	CurrentHealth = _CurrentHealth;
// }

// Called every frame
// void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
// {
// 	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

// 	// ...
// }

