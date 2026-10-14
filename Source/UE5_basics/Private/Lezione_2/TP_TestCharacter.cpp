// Fill out your copyright notice in the Description page of Project Settings.


#include "Lezione_2/TP_TestCharacter.h"

// Sets default values
ATP_TestCharacter::ATP_TestCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATP_TestCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATP_TestCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATP_TestCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

