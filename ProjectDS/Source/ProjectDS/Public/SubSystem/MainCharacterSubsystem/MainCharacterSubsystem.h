// All rights reserved by Jellyfish-zero.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MainCharacterSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTDS_API UMainCharacterSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:

	FORCEINLINE int32 GetCurrentCharacterMaxHealth() const;

	FORCEINLINE int32 GetCurrentCharacterMaxMana() const;

	FORCEINLINE int32 GetCurrentCharacterMaxStamina() const;

protected:

private:

	UPROPERTY()
	int32 MaxHealth = 100;

	UPROPERTY()
	int32 MaxMana = 100;

	UPROPERTY()
	int32 MaxStamina = 100;

};

FORCEINLINE int32 UMainCharacterSubsystem::GetCurrentCharacterMaxHealth() const
{
	return MaxHealth;
}

FORCEINLINE int32 UMainCharacterSubsystem::GetCurrentCharacterMaxMana() const
{
	return MaxMana;
}

FORCEINLINE int32 UMainCharacterSubsystem::GetCurrentCharacterMaxStamina() const
{
	return MaxStamina;
}