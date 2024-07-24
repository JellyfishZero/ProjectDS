// All rights reserved by Jellyfish-zero.


#include "Actor/Projectile/AttackProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "SubSystem/CombatSubsystem/CombatSubsystem.h"

// Sets default values
AAttackProjectile::AAttackProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ProjectileMovementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectMovementComp"));
	ProjectileMovementComp->InitialSpeed = 3000.0f;
	ProjectileMovementComp->MaxSpeed = 3000.0f;
	ProjectileMovementComp->bRotationFollowsVelocity = true;
	ProjectileMovementComp->bShouldBounce = false;

	InitialLifeSpan = 3.f; // 暫時先設定生命週期為3秒
}

// Called when the game starts or when spawned
void AAttackProjectile::BeginPlay()
{
	Super::BeginPlay();

	CombatSystem = GetWorld()->GetGameInstance()->GetSubsystem<UCombatSubsystem>();
	if (CombatSystem.IsValid())
	{
		CombatSystem->RegisterProjectile(this); //向戰鬥系統註冊Projectile
	}

}

// Called every frame
void AAttackProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAttackProjectile::BeginDestroy()
{
	if (CombatSystem.IsValid())
	{
		CombatSystem->UnregisterProjectile(this); //向戰鬥系統取消註冊Projectile
	}

	Super::BeginDestroy();
}

