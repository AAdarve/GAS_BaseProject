// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UI/Widgets/AuraUserWidget.h"
#include "UI/WidgetControllers/AuraWidgetController.h"
#include "AuraHUD.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraHUD : public AHUD
{
	GENERATED_BODY()
protected:
	
public:
	UFUNCTION(BlueprintCallable)
	UHUDWidgetController* GetHudWidgetController(const FWidgetControllerParams& WCParams);
	UFUNCTION(BlueprintCallable)
	void InitHUD(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);
public: 
	UPROPERTY()
	TObjectPtr<UAuraUserWidget> HUDWidget;

	UPROPERTY()
	TObjectPtr<UHUDWidgetController> HUDWidgetController;

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraUserWidget> HUDWidgetClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraWidgetController> HUDWidgetControllerClass;
};
