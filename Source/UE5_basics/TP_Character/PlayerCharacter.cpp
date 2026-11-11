// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// funzione che incrementa il contatore
void APlayerCharacter::IncrementaContatore()
{
	// L'attore incrementa il contatore SOLO se il player ha la palla
	if (HaLaPalla)
	{
		Contatore++;
		UE_LOG(LogTemp, Warning, TEXT("Contatore aggiornato! Nuovo valore: %d"), Contatore);
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Il Player non ha la palla. Contatore non incrementato."));
	}
}

