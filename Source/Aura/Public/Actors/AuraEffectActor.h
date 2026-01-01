// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "GameplayEffect.h"
#include "AuraEffectActor.generated.h"



UCLASS()
class AURA_API AAuraEffectActor : public AActor
{
	GENERATED_BODY()
	
	//Functions
public:	
	AAuraEffectActor();
	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* EffectTarget, TSubclassOf<UGameplayEffect> EffectClass);

	//Variables
protected:
	UPROPERTY(BlueprintReadOnly, Category = "Gameplay Effects")
	TSubclassOf<UGameplayEffect> InstantEffectClass;
};
