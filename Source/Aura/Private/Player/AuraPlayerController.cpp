// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;
}

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	CursorTrace();
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(BasicContext);
	UEnhancedInputLocalPlayerSubsystem* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	
	if (InputSubsystem)
	{
		InputSubsystem->AddMappingContext(BasicContext,0);
	}

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetHideCursorDuringCapture(false);
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	SetInputMode(InputModeData);
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
}

void AAuraPlayerController::Move(const FInputActionValue& value)
{
	const FVector2D InputAxisVector = value.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.0, Rotation.Yaw, 0.0);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

void AAuraPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;

	LastActor = ThisActor;
	ThisActor = CursorHit.GetActor();
	//ThisActor = nullptr;
	//AActor* HitActor = CursorHit.GetActor();
	//if (HitActor && HitActor->Implements<UInteractableInterface>())
	//{
	//	ThisActor.SetObject(HitActor);
	//	ThisActor.SetInterface(Cast<IInteractableInterface>(HitActor));
	//}

	/*
	Line trace from cursor.There are several scenarios :
		A.LastACtor null ThiSACtor null
		- Do nothing
		B.lastActor is nutt ThisActor Is vatíd
		- Hightáght rhIsActor
		C.lastActor is vatíd ThisActor Is null
		- UnHightight lastActor
		D. Both actors ore vatid.but LastActor != ThisActor
		- UnHighlight LastActor, and Highlight ThisActor
		E.Both actors are vatid. and are the sane actor
		- Do nothing
	*/

	if (LastActor == nullptr)
	{
		if (ThisActor != nullptr)
		{
			// B.
			ThisActor->HighlightActor();
		}
	}
	else
	{
		if (ThisActor != nullptr)
		{
			// D.
			if (LastActor != ThisActor)
			{
				LastActor->UnhighlightActor();
				ThisActor->HighlightActor();
			}
		}
		else
		{
			// C.
			LastActor->UnhighlightActor();
		}
	}
}
