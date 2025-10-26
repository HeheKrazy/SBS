// Copyright HeheKrazy

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "SBSAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class SBS_API USBSAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:

	virtual void OnGiveAbility(FGameplayAbilitySpec& AbilitySpec) override;
	virtual void OnRep_ActivateAbilities() override;
	
	UFUNCTION(BlueprintCallable, Category = "SBS|Abilities")
	void SetAbilityLevel(TSubclassOf<UGameplayAbility> AbilityClass, int32 NewLevel);


	UFUNCTION(BlueprintCallable, Category = "SBS|Abilities")
	void AddToAbilityLevel(TSubclassOf<UGameplayAbility> AbilityClass, int32 Level = 1);
private:

	void HandleAutoActivatedAbility(const FGameplayAbilitySpec& AbilitySpec);
};
