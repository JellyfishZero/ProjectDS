// All rights reserved by Jellyfish-zero.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerStatusComp.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTDS_API UPlayerStatusComp : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerStatusComp();

	void InitPlayerStatus();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
		

private:

	UPROPERTY()
	int32 MaxHealth = 100;

	UPROPERTY()
	int32 CurrentHealth;

	UPROPERTY()
	int32 MaxMana = 100;

	UPROPERTY()
	int32 CurrentMana;

	UPROPERTY()
	int32 MaxStamina = 100;

	UPROPERTY()
	int32 CurrentStamina;

};
