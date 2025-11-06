// Copyright HeheKrazy

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SBS_Projectile.generated.h"

class UProjectileMovementComponent;
class UGameplayEffect;

UCLASS()
class SBS_API ASBS_Projectile : public AActor
{
	GENERATED_BODY()
	
public:	
	ASBS_Projectile();

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "SBS|Damage", meta = (ExposeOnSpawn, ClampMin = "0.0"))
	float Damage{ 10.f };

	UFUNCTION(BlueprintImplementableEvent, Category = "SBS|Projectile")
	void SpawnImpactEffects();

private:
	UPROPERTY(VisibleAnywhere, Category = "SBS|Projectile")
	TObjectPtr<UProjectileMovementComponent> ProjectileMovement;

	UPROPERTY(EditDefaultsOnly, Category = "SBS|Damage")
	TSubclassOf<UGameplayEffect> DamageEffect;
};
