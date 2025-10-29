// Copyright HeheKrazy


#include "Characters/SBS_BaseCharacter.h"
#include "AbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"

namespace SBSTags
{
	const FName Player = FName("Player");
}

ASBS_BaseCharacter::ASBS_BaseCharacter()
{

	PrimaryActorTick.bCanEverTick = false;

	// Tick and refresh bone transforms whether rendered or not - for bone updates on a dedicated server
	GetMesh()->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPoseAndRefreshBones;
}

void ASBS_BaseCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ThisClass, bAlive);
}

UAbilitySystemComponent* ASBS_BaseCharacter::GetAbilitySystemComponent() const
{
	return nullptr;
}

void ASBS_BaseCharacter::GiveStartupAbilities()
{
	if (!IsValid(GetAbilitySystemComponent())) return;
	for(const auto & Ability : StartupAbilities)
	{
		FGameplayAbilitySpec AbilitySpec(Ability);
		GetAbilitySystemComponent()->GiveAbility(AbilitySpec);
	}

}

void ASBS_BaseCharacter::InitializeAttributes() const
{
	ApplyGameplayEffectToSelfChecked(InitializeAttributesEffect);
}

void ASBS_BaseCharacter::OnHealthChanged(const FOnAttributeChangeData& AttributeChangeData)
{
	if(AttributeChangeData.NewValue <= 0.f)
	{
		HandleDeath();
	}
}

void ASBS_BaseCharacter::HandleDeath()
{
	bAlive = false;
}

void ASBS_BaseCharacter::ApplyGameplayEffectToSelfChecked(TSubclassOf<UGameplayEffect> Effect) const
{
	checkf(IsValid(Effect), TEXT("%s is not valid on %s. Please check the Blueprint."), *Effect->GetName(), *GetName());

	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(Effect, 1, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
}

void ASBS_BaseCharacter::HandleRespawn()
{
	bAlive = true;
}

void ASBS_BaseCharacter::ResetAttributes()
{
	ApplyGameplayEffectToSelfChecked(ResetAttributesEffect);
}





