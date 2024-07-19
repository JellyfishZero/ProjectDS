// All rights reserved by Jellyfish-zero.


#include "Controller/MainGamePC.h"
#include "Actor/Pawn/Character/PlayerCharacter.h"
#include "EnhancedInputSubsystems.h"

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
}
