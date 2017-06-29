// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"

struct Message
{
	FString message;
	float time;
	FColor frontColor;
	FColor backColor;
	UTexture2D* texture;

	Message()
	{
		time = 5;
		frontColor = FColor::White;
		backColor = FColor::Blue;
		texture = nullptr;
	}

	Message(FString iMessage, float iTime, FColor iFrontColor, FColor iBackColor):
		message(iMessage), time(iTime), frontColor(iFrontColor), backColor(iBackColor), texture(nullptr)
	{}

	Message(UTexture2D* iTexture, FString iMessage, float iTime, FColor iFrontColor, FColor iBackColor):
		message(message), time(iTime), frontColor(iFrontColor), backColor(iBackColor), texture(iTexture)
	{}
};

#include "MyHUD.generated.h"

UCLASS()
class GOLDENEGG_API AMyHUD : public AHUD
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUDFont)
	UFont* hudFont;

	TArray<Message> message; // массив возможных сообщений
	FVector2D dimScreen; // размеры экрана

	virtual void DrawHUD() override;	
	void drawMessages();
	void addMessage();
};
