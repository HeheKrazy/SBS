// Copyright HeheKrazy

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "Components/WidgetComponent.h"
#include "SBS_WidgetComponent.generated.h"

/**
 * 
 */
class ASBS_BaseCharacter;
class USBSAbilitySystemComponent;
class USBS_AttributeSet;
class UAbilitySystemComponent;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SBS_API USBS_WidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TMap<FGameplayAttribute, FGameplayAttribute> AttributeMap;

private:
	TWeakObjectPtr<ASBS_BaseCharacter> SBSCharacter;
	TWeakObjectPtr<USBSAbilitySystemComponent> AbilitySystemComponent;
	TWeakObjectPtr<USBS_AttributeSet> AttributeSet;

	void InitAbilitySystemData();
	bool IsASCInitialized() const;

	UFUNCTION()
	void OnASCInitialized(UAbilitySystemComponent* ASC, UAttributeSet* AS);
	
	void InitializeAttributeDelegate();

	UFUNCTION()
	void BindToAttributeChange();

	void BindWidgetToAttributeChanges(UWidget* WidgetObject, const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair) const;

};
