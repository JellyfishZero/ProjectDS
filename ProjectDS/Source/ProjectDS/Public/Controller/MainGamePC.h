// All rights reserved by Jellyfish-zero.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainGamePC.generated.h"

class UInputMappingContext;
class UInputAction;
class APlayerCharacter;
struct FInputActionValue;

/**
 * 
 */
UCLASS()
class PROJECTDS_API AMainGamePC : public APlayerController
{
	GENERATED_BODY()

public:

#pragma region API

	UFUNCTION(BlueprintCallable)
	APlayerCharacter* GetPlayerCharacter() const;

#pragma endregion


protected:

	void BeginPlay() override;

	void SetupInputComponent() override;

#pragma region InputMappingContexts

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	UInputMappingContext* DSGameInputContext;

#pragma endregion

#pragma region InputActions

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	UInputAction* MoveAction;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	UInputAction* LookAction;

#pragma endregion

private:

#pragma region NormalGameInput

	void Move(const FInputActionValue& Value);

	void Look(const FInputActionValue& Value);

#pragma endregion

	/* 利用GetPawn Cast而來的PlayerCharacter，若有值表示當前玩家控制器有設定繼承PlayerCharacter的Character */
	APlayerCharacter* PlayerCharacter;

};