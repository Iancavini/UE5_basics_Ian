// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent_Test.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE5_BASICS_API UHealthComponent_Test : public UActorComponent
{
	GENERATED_BODY()

public:	
	UHealthComponent_Test();
	
	void GetDamage(int Amount);
	
	// funzione per curare il personaggio
	UFUNCTION(BlueprintCallable, Category = "Health")
	void Heal(int Amount);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	int MaxHealth = 100;

	// configurazione auto-recovery
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Auto Recovery")
	bool bEnableAutoRecovery = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Auto Recovery", meta = (EditCondition = "bEnableAutoRecovery"))
	float TimeWithoutDamageToRecover = 3.0f; // Secondi di attesa prima di iniziare a recuperare

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Auto Recovery", meta = (EditCondition = "bEnableAutoRecovery"))
	float HealthRecoveryPerSecond = 10.0f; // Quantità di vita recuperata al secondo

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
private:
	int currentHealth;
	float lastDamageTime = 0.0f; // Traccia l'istante dell'ultimo danno subito
};