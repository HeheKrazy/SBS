// Copyright HeheKrazy

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AbilitySystem/SBS_AttributeSet.h"
#include "SBS_AttributeWidget.generated.h"

/**
 * 
 */
UCLASS()
class SBS_API USBS_AttributeWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "SBS|Attributes")
	FGameplayAttribute Attribute;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "SBS|Attributes")
	FGameplayAttribute MaxAttribute;

	bool MatchesAttributes(const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair) const;

	void OnAttributeChanged(const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair, USBS_AttributeSet* AttributeSet);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "On Attribute Changed"))
	void BP_OnAttributeChanged(float NewValue, float NewMaxValue);

};
