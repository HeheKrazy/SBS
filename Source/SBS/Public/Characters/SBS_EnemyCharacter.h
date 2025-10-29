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
	virtual UAttributeSet* GetAttributeSet() const override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "SBS|AI")
	float AcceptanceRadius{500.f};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "SBS|AI")
	float MinAttackDelay{.1f};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "SBS|AI")
	float MaxAttackDelay{.5f};


protected:

	virtual void BeginPlay() override;


private:

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

};
