// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraCharBase.h"

// Sets default values
AAuraCharBase::AAuraCharBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), "WeaponSocket");
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AAuraCharBase::BeginPlay()
{
	Super::BeginPlay();
}

