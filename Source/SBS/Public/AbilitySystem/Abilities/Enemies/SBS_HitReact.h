// Copyright HeheKrazy

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/SBS_GameplayAbility.h"
#include "SBS_HitReact.generated.h"

/**
 * 
 */
UCLASS()
class SBS_API USBS_HitReact : public USBS_GameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "SBS|Abilities")
	void CacheHitDirecionVectors(AActor* Instigator);

	UPROPERTY(BlueprintReadOnly, Category = "SBS|Abilities")
	FVector AvatarForward;

	UPROPERTY(BlueprintReadOnly, Category = "SBS|Abilities")
	FVector ToInstigator;
	
};
