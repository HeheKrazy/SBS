// Copyright HeheKrazy

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Async/AbilityAsync_WaitGameplayEvent.h"
#include "SBS_WaitGameplayEvent.generated.h"

/**
 * 
 */

UCLASS()
class SBS_API USBS_WaitGameplayEvent : public UAbilityAsync_WaitGameplayEvent
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Ability|Async", meta = (DefaultToSelf = "TargetActor", BlueprintInternalUseOnly = "TRUE"))
	static USBS_WaitGameplayEvent* WaitGameplayEventToActorProxy(AActor* TargetActor,UPARAM(meta=(GameplayTagFilter="GameplayEventTagsCategory")) FGameplayTag EventTag, bool OnlyTriggerOnce = false, bool OnlyMatchExact = true);

	void StartActivation();
	
};
