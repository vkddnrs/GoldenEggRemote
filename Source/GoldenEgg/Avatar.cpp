// Fill out your copyright notice in the Description page of Project Settings.

#include "GoldenEgg.h"
#include "Avatar.h"


// Sets default values
AAvatar::AAvatar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	sensitivity_of_mouse = 200;

}

// Called when the game starts or when spawned
void AAvatar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAvatar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAvatar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Forward", this, &AAvatar::MoveForward);
	PlayerInputComponent->BindAxis("Right", this, &AAvatar::MoveRight);
	PlayerInputComponent->BindAxis("Left", this, &AAvatar::MoveLeft);
	PlayerInputComponent->BindAxis("Back", this, &AAvatar::MoveBack);
	PlayerInputComponent->BindAxis("Yaw", this, &AAvatar::Yaw);
	PlayerInputComponent->BindAxis("Pitch", this, &AAvatar::Pitch);
}


void AAvatar::MoveForward(float amount)
{
	// метод работает только когда Контроллер уже запущен и величина перемещения отлична от нуля
	if (Controller && amount)
	{
		FVector forward = GetActorForwardVector();
		AddMovementInput(forward, amount); // передвигаем игрока
	}
}

void AAvatar::MoveRight(float amount)
{
	// метод работает только когда Контроллер уже запущен и величина перемещения отлична от нуля
	if (Controller && amount)
	{
		FVector right = GetActorRightVector();
		AddMovementInput(right, amount); // передвигаем игрока
	}
}

void AAvatar::MoveLeft(float amount)
{
	// метод работает только когда Контроллер уже запущен и величина перемещения отлична от нуля
	if (Controller && amount)
	{
		FVector left = - GetActorRightVector();
		AddMovementInput(left, amount); // передвигаем игрока
	}
}

void AAvatar::MoveBack(float amount)
{
	// метод работает только когда Контроллер уже запущен и величина перемещения отлична от нуля
	if (Controller && amount)
	{
		FVector back = -GetActorForwardVector();
		AddMovementInput(back, amount); // передвигаем игрока
	}
}

void AAvatar::Yaw(float amount)
{
	AddControllerYawInput(sensitivity_of_mouse * amount * GetWorld()->GetDeltaSeconds());
}

void AAvatar::Pitch(float amount)
{
	AddControllerPitchInput(sensitivity_of_mouse * amount * GetWorld()->GetDeltaSeconds());
}

