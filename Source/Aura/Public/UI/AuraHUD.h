// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UI/Widgets/AuraUserWidget.h"
#include "AuraHUD.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraHUD : public AHUD
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
public: 
	UPROPERTY()
	TObjectPtr<UAuraUserWidget> HUDWidget;

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraUserWidget> HUDWidgetClass;
	
};
