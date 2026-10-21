// Fill out your copyright notice in the Description page of Project Settings.


#include "Lezione_2/Component/HealthComponent_Test.h"

// Sets default values for this component's properties
UHealthComponent_Test::UHealthComponent_Test()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UHealthComponent_Test::GetDamage(int Amount)
{
	if (Amount != 0)
	{
		const auto ActualDamage = FMath::Abs(Amount);
		currentHealth = FMath::Clamp(currentHealth - ActualDamage, 0, MaxHealth);
	}
}

// Called when the game starts
void UHealthComponent_Test::BeginPlay()
{
	Super::BeginPlay();
	
	currentHealth = MaxHealth;
	
}


// Called every frame
void UHealthComponent_Test::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

