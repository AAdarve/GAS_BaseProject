// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraPlayerChar.h"
#include "Player/AuraPlayerState.h"

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
}
