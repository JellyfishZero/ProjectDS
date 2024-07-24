// All rights reserved by Jellyfish-zero.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameDefine/CombatDefine.h"
#include "AttackProjectile.generated.h"

class UCombatSubsystem;
class UProjectileMovementComponent;

UCLASS()
class PROJECTDS_API AAttackProjectile : public AActor
{
	GENERATED_BODY()
	
public:	

	// Sets default values for this actor's properties
	AAttackProjectile();

#pragma region API

	FORCEINLINE ECampType GetCampType() const;

#pragma endregion

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 暫時還沒有物件池的概念所以會先把AttackProjectile在發射後一定時間刪掉，因此這邊需要處理unregister的狀態
	virtual void BeginDestroy() override;

#pragma region Subsystem

	TWeakObjectPtr<UCombatSubsystem> CombatSystem;	// TODO: 這邊引用CombatSystem是否需要解耦合？

#pragma endregion

#pragma region ActorComps

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UProjectileMovementComponent* ProjectileMovementComp;

#pragma endregion

private:

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "CampType", meta = (AllowPrivateAccess=true))
	ECampType BelongedCamp; // 其實這不應該在藍圖裡設定，但暫時先這麼做

};

FORCEINLINE ECampType AAttackProjectile::GetCampType() const
{
	return BelongedCamp;
}