// All rights reserved by Jellyfish-zero.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "CombatSubsystem.generated.h"

class AAttackProjectile;

/**
 * 
 */
UCLASS()
class PROJECTDS_API UCombatSubsystem : public UGameInstanceSubsystem
{

	GENERATED_BODY()
	
public:

	void Initialize(FSubsystemCollectionBase& Collection) override;

#pragma region API

	void RegisterProjectile(AAttackProjectile* Projectile);

	void UnregisterProjectile(AAttackProjectile* Projectile);

	bool CheckIsPlayerPreciseDodge(float InPreciseDistance) const;

#pragma endregion

protected:



private:
	
	UPROPERTY()
	TSet<AAttackProjectile*> KingdomProjectile;

};
