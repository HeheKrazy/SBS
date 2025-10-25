// Copyright HeheKrazy

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/SBS_GameplayAbility.h"
#include "SBS_Primary.generated.h"

/**
 * 
 */
UCLASS()
class SBS_API USBS_Primary : public USBS_GameplayAbility
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "SBS|Abilities")
	TArray<AActor*> HitBoxOverlapTest();

	UFUNCTION(BlueprintCallable, Category = "SBS|Abilities")
	void SendHitReactToActors(const TArray<AActor*>& ActorsHit);

private:

void DrawHitBoxOverlapDebugs(const TArray<FOverlapResult>& OverlapResults, const FVector HitBoxLocation) const;

	UPROPERTY(EditDefaultsOnly, Category = "SBS|Abilities")
	float HitBoxRadius = 100.f;

	UPROPERTY(EditDefaultsOnly, Category = "SBS|Abilities")
	float HitBoxForwardOffset = 200.f;

	UPROPERTY(EditDefaultsOnly, Category = "SBS|Abilities")
	float HitBoxElevationOffset = 20.f;
	
};
