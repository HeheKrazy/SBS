// Copyright HeheKrazy

#pragma once

#include "CoreMinimal.h"
#include "Characters/SBS_BaseCharacter.h"
#include "SBS_EnemyCharacter.generated.h"

/**
 * 
 */

class UAbilitySystemComponent;
class UAttributeSet;

UCLASS()
class SBS_API ASBS_EnemyCharacter : public ASBS_BaseCharacter
{
	GENERATED_BODY()

public:

	ASBS_EnemyCharacter();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:

	virtual void BeginPlay() override;


private:

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

};
