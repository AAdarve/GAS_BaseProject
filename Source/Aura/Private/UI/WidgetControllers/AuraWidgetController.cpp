// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetControllers/AuraWidgetController.h"

void UAuraWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	PlayerState = WCParams.PlayerState;
	AttributeSet = WCParams.AttributeSet;
}
