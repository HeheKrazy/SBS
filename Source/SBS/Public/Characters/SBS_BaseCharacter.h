// Copyright HeheKrazy

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "SBS_BaseCharacter.generated.h"

// Different than a GameplayTag, but used for similar purposes.
namespace SBSTags
{
	extern SBS_API const FName Player;
}

struct FOnAttributeChangeData;
class UGameplayAbility;
class UGameplayEffect;
class UAttributeSet;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FASCInitialized, UAbilitySystemComponent*, ASC, UAttributeSet*, AS);

UCLASS(Abstract)
class SBS_API ASBS_BaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ASBS_BaseCharacter();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual UAttributeSet* GetAttributeSet() const { return nullptr; }
	bool IsAlive() const { return bAlive; }
	void SetAlive(bool bAliveStatus) { bAlive = bAliveStatus; }

	// Delegates
	UPROPERTY(BlueprintAssignable)
	FASCInitialized OnASCInitialized;

	UFUNCTION(BlueprintCallable, Category = "SBS|Death")
	virtual void HandleRespawn();

	UFUNCTION(BlueprintCallable, Category = "SBS|Attributes")
	virtual void ResetAttributes();

protected:

	void GiveStartupAbilities();
	void InitializeAttributes()const;

	void OnHealthChanged(const FOnAttributeChangeData& AttributeChangeData);	
	virtual void HandleDeath();

	void ApplyGameplayEffectToSelfChecked(TSubclassOf<UGameplayEffect> Effect) const;

private:

	UPROPERTY(EditDefaultsOnly, Category = "SBS|Effects")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "SBS|Effects")
	TSubclassOf<UGameplayEffect> InitializeAttributesEffect;

	UPROPERTY(EditDefaultsOnly, Category = "SBS|Effects")
	TSubclassOf<UGameplayEffect> ResetAttributesEffect;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Replicated)
	bool bAlive = true;

	
};
