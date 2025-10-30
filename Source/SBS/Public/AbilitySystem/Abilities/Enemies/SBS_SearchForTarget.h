// Copyright HeheKrazy

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/SBS_GameplayAbility.h"
#include "SBS_SearchForTarget.generated.h"

namespace EPathFollowingResult
{
	enum Type : int;
}


class ASBS_EnemyCharacter;
class AAIController;
class USBS_WaitGameplayEvent;
class UAbilityTask_WaitDelay;
class ASBS_BaseCharacter;
class UAITask_MoveTo;
/**
 * 
 */
UCLASS()
class SBS_API USBS_SearchForTarget : public USBS_GameplayAbility
{
	GENERATED_BODY()
	
public:
	USBS_SearchForTarget();

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	TWeakObjectPtr<ASBS_EnemyCharacter> OwningEnemy;
	TWeakObjectPtr<AAIController> OwningAIController;
	TWeakObjectPtr<ASBS_BaseCharacter> TargetBaseCharacter;

private:

	UPROPERTY()
	TObjectPtr<USBS_WaitGameplayEvent> WaitGameplayEventTask;

	UPROPERTY()
	TObjectPtr<UAbilityTask_WaitDelay> SearchDelayTask;

	UPROPERTY()
	TObjectPtr<UAITask_MoveTo> MoveToLocationOrActorTask;

	UPROPERTY()
	TObjectPtr<UAbilityTask_WaitDelay> AttackDelayTask;
	void StartSearch();
	
	UFUNCTION()
	void EndAttackEventReceived(FGameplayEventData Payload);

	UFUNCTION()
	void Search();

	void MoveToTargetAndAttack();

	UFUNCTION()
	void AttackTarget(TEnumAsByte<EPathFollowingResult::Type> Result, AAIController* AIController);

	UFUNCTION()
	void Attack();


};
