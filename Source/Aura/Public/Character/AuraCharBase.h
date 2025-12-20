// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AuraCharBase.generated.h"

UCLASS()
class AURA_API AAuraCharBase : public ACharacter
{
	GENERATED_BODY()

public:
	AAuraCharBase();

protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere)
	TObjectPtr<USkeletalMeshComponent> Weapon;
};
