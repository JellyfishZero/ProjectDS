// All rights reserved by Jellyfish-zero.


#include "Controller/MainGamePC.h"
#include "Actor/Pawn/Character/PlayerCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "InputAction.h"
#include "Blueprint/UserWidget.h"

void AMainGamePC::BeginPlay()
{
	Super::BeginPlay();

	/* 綁定Input Mapping */
	UEnhancedInputLocalPlayerSubsystem* EnhancedInputLocalPlayerSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (ensure(IsValid(EnhancedInputLocalPlayerSubsystem)))
	{
		EnhancedInputLocalPlayerSubsystem->AddMappingContext(DSGameInputContext, 0);
	}

	/* 初始化鏡頭上下角度 */
	PlayerCameraManager->ViewPitchMax = MaxPitchAngle;
	PlayerCameraManager->ViewPitchMin = MinPitchAngle;

	MainGameHUD = CreateWidget<UUserWidget>(this, MainGameHUDTemplate, FName(TEXT("MainGameUI")));
	if (IsValid(MainGameHUD))
	{
		MainGameHUD->AddToViewport();
	}
}

void AMainGamePC::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	if (IsValid(EnhancedInputComponent))
	{
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMainGamePC::Look);
	}
}

void AMainGamePC::Look(const FInputActionValue& Value)
{
	FVector2D LookVector = Value.Get<FVector2D>();
	AddYawInput(LookVector.X);
	AddPitchInput(LookVector.Y);
}
