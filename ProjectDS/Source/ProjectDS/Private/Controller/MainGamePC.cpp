// All rights reserved by Jellyfish-zero.


#include "Controller/MainGamePC.h"
#include "Actor/Pawn/Character/PlayerCharacter.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"

APlayerCharacter* AMainGamePC::GetPlayerCharacter() const
{
	return PlayerCharacter;
}

void AMainGamePC::BeginPlay()
{
	Super::BeginPlay();

	/* 綁定Input Mapping */
	UEnhancedInputLocalPlayerSubsystem* EnhancedInputLocalPlayerSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (ensure(IsValid(EnhancedInputLocalPlayerSubsystem)))
	{
		EnhancedInputLocalPlayerSubsystem->AddMappingContext(DSGameInputContext, 0);
	}

	/*  */
	PlayerCharacter = Cast<APlayerCharacter>(GetPawn());

}

void AMainGamePC::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	if (ensure(IsValid(EnhancedInputComponent)))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMainGamePC::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMainGamePC::Look);
	}
}

void AMainGamePC::Move(const FInputActionValue& Value)
{
	if (PlayerCharacter)
	{
		PlayerCharacter->Move(Value);
	}
}

void AMainGamePC::Look(const FInputActionValue& Value)
{
	FVector2D LookVector = Value.Get<FVector2D>();
	
	AddYawInput(LookVector.X);
	AddPitchInput(LookVector.Y);
}