// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraPlayerChar.h"
#include "Player/AuraPlayerState.h"
#include "UI/AuraHUD.h"

class AAuraHUD;

AAuraPlayerChar::AAuraPlayerChar()
{
	
}

void AAuraPlayerChar::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Init ability actor info for server
	InitAbilityActorInfo();
}

void AAuraPlayerChar::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// Init ability actor info for client
	InitAbilityActorInfo();
}

void AAuraPlayerChar::InitAbilityActorInfo()
{
	AAuraPlayerState* PS = GetPlayerState<AAuraPlayerState>();
	check(PS);
	PS->GetAbilitySystemComponent()->InitAbilityActorInfo(PS, this);
	AbilitySystemComponent = PS->GetAbilitySystemComponent();
	AttributeSet = PS->GetAttributeSet();

	//This controller only exist in owning client and server, others will fail this condition
	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		//HUD only exists on clinet, server will fail this
		if (AAuraHUD* HUD = PC->GetHUD<AAuraHUD>())
		{
			HUD->InitHUD(PC, PS, AbilitySystemComponent, AttributeSet);
		}
	}
}
