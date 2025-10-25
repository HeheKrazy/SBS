// Copyright HeheKrazy

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "SBS_AttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)




/**
* EXAMPLE Setup for a single attribute called Health
 * 	UPROPERTY(BlueprintReadOnly,ReplicatedUsing = OnRep_Health")
	FGameplayAttributeData Health;

	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldValue);

	ATTRIBUTE_ACCESSORS(USBS_AttributeSet, Health)
 *
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAttributesInitialized);


UCLASS()
class SBS_API USBS_AttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	UPROPERTY(BlueprintAssignable)
	FOnAttributesInitialized OnAttributesInitialized;

	UPROPERTY(ReplicatedUsing = OnRep_AttributesInitialized)
	bool bAttributesInitialized = false;

	UFUNCTION()
	void OnRep_AttributesInitialized();

	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldValue);

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing = OnRep_Health)
	FGameplayAttributeData Health;

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing = OnRep_Mana)
	FGameplayAttributeData Mana;

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing = OnRep_MaxMana)
	FGameplayAttributeData MaxMana;

	ATTRIBUTE_ACCESSORS(USBS_AttributeSet, Health)

	ATTRIBUTE_ACCESSORS(USBS_AttributeSet, MaxHealth)

	ATTRIBUTE_ACCESSORS(USBS_AttributeSet, Mana)

	ATTRIBUTE_ACCESSORS(USBS_AttributeSet, MaxMana)

};
