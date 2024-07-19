// All rights reserved by Jellyfish-zero.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainGamePC.generated.h"

class UInputMappingContext;

/**
 * 
 */
UCLASS()
class PROJECTDS_API AMainGamePC : public APlayerController
{
	GENERATED_BODY()

protected:

	void BeginPlay() override;

#pragma region InputMappingContexts

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	UInputMappingContext* DSGameInputContext;

#pragma endregion

#pragma region CameraLimitParams

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	float MaxPitchAngle = 45.f;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	float MinPitchAngle = -45.f;

#pragma endregion


};