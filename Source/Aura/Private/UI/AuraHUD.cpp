// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/AuraHUD.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "UI/WidgetControllers/HUDWidgetController.h"
#include "Blueprint/UserWidget.h"

UHUDWidgetController* AAuraHUD::GetHudWidgetController(const FWidgetControllerParams& WCParams)
{
	if (HUDWidgetController == nullptr)
	{
		HUDWidgetController = NewObject<UHUDWidgetController>(this, HUDWidgetControllerClass);
		HUDWidgetController->SetWidgetControllerParams(WCParams);
	}
	return HUDWidgetController;
}

void AAuraHUD::InitHUD(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	checkf(HUDWidgetClass, TEXT("HUd widget class not initialized"));
	checkf(HUDWidgetControllerClass, TEXT("HUd widget controller class not initialized"));

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), HUDWidgetClass);
	HUDWidget = Cast<UAuraUserWidget>(Widget);

	const FWidgetControllerParams WCParams(PC, PS, ASC, AS);
	UHUDWidgetController* HUDController = GetHudWidgetController(WCParams);

	HUDWidget->SetWidgetController(HUDController);
	HUDController->BroadcastInitialValues();
	HUDWidget->AddToViewport();
}