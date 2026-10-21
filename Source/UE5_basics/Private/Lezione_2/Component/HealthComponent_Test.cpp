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
		
		// Aggiorna il timestamp dell'ultimo danno ricevuto
		if (UWorld* World = GetWorld())
		{
			lastDamageTime = World->GetTimeSeconds();
		}
	}
}

void UHealthComponent_Test::Heal(int Amount)
{
	if (Amount > 0 && currentHealth < MaxHealth && currentHealth > 0)
	{
		currentHealth = FMath::Clamp(currentHealth + Amount, 0, MaxHealth);
	}
}

// Called when the game starts
void UHealthComponent_Test::BeginPlay()
{
	Super::BeginPlay();
	
	currentHealth = MaxHealth;
	
	if (UWorld* World = GetWorld())
	{
		lastDamageTime = World->GetTimeSeconds();
	}
}


// Called every frame
void UHealthComponent_Test::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Gestione dell'Auto-Recovery
	if (bEnableAutoRecovery && currentHealth < MaxHealth && currentHealth > 0)
	{
		if (UWorld* World = GetWorld())
		{
			float CurrentTime = World->GetTimeSeconds();
			
			// Controlla se è passato abbastanza tempo dall'ultimo colpo subito
			if (CurrentTime - lastDamageTime >= TimeWithoutDamageToRecover)
			{
				// Recupero incrementale basato sul DeltaTime per renderlo fluido
				float RecoveryThisFrame = HealthRecoveryPerSecond * DeltaTime;
				currentHealth = FMath::Clamp(FMath::RoundToInt(currentHealth + RecoveryThisFrame), 0, MaxHealth);
			}
		}
	}
}

