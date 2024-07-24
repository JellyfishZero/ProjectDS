// All rights reserved by Jellyfish-zero.


#include "SubSystem/CombatSubsystem/CombatSubsystem.h"
#include "Actor/Projectile/AttackProjectile.h"
#include "GameDefine/CombatDefine.h"

void UCombatSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	
}

void UCombatSubsystem::RegisterProjectile(AAttackProjectile* Projectile)
{
	if (IsValid(Projectile) && !KingdomProjectile.Contains(Projectile))
	{
		switch (Projectile->GetCampType())
		{
		case ECampType::None:
			break;
		case ECampType::Confederation:
			break;
		case ECampType::Kingdom:
			KingdomProjectile.Emplace(Projectile);
		default:
			break;
		}
	}
}

void UCombatSubsystem::UnregisterProjectile(AAttackProjectile* Projectile)
{
	if (IsValid(Projectile) && !KingdomProjectile.Contains(Projectile))
	{
		switch (Projectile->GetCampType())
		{
		case ECampType::None:
			break;
		case ECampType::Confederation:
			break;
		case ECampType::Kingdom:
			KingdomProjectile.Remove(Projectile);
		default:
			break;
		}
	}
}

bool UCombatSubsystem::CheckIsPlayerPreciseDodge(float InPreciseDistance) const
{
	if (KingdomProjectile.Num() <= 0)
	{
		//沒有任何敵方彈幕
		return false; 
	}
	APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!ensure(IsValid(PlayerPawn)))
	{
		//找不到玩家角色
		return false;
	}

	for (AAttackProjectile* Projectile : KingdomProjectile)
	{
		if (IsValid(Projectile))
		{
			double AttackToPlayer = FVector::Dist(Projectile->GetActorLocation(), PlayerPawn->GetActorLocation());
			if (AttackToPlayer <= InPreciseDistance)
			{
				return true;
			}
		}
	}

	return false;
}

