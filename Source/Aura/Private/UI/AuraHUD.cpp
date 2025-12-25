// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/AuraHUD.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Blueprint/UserWidget.h"

void AAuraHUD::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), HUDWidgetClass);
	Widget->AddToViewport();
}
