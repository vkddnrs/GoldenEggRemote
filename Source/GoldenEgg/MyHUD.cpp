// Fill out your copyright notice in the Description page of Project Settings.

#include "GoldenEgg.h"
#include "MyHUD.h"

void AMyHUD::DrawHUD()
{
	// call superclass DrawHUD() function first
	Super::DrawHUD();

	// затем переходим к изображению вашей задумки.
	// мы можем изобразить линии..
	//DrawLine(200, 300, 400, 300, FLinearColor::Blue);

	// and we can draw text
	DrawText("Hare Krishna!", FLinearColor::White, 210, 270,
		hudFont);
}
