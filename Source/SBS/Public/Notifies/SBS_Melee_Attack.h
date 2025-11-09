// Copyright HeheKrazy

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "SBS_Melee_Attack.generated.h"

/**
 * 
 */
UCLASS()
class SBS_API USBS_Melee_Attack : public UAnimNotifyState
{
	GENERATED_BODY()

public:

	virtual void NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime, const FAnimNotifyEventReference& EventReference) override;


private:

	UPROPERTY(EditAnywhere, Category = "SBS|Debug")
	bool bDrawDebug = true;

	UPROPERTY(EditAnywhere, Category = "SBS|Socket")
	FName SocketName{"FX_Trail_01_R"};

	UPROPERTY(EditAnywhere, Category = "SBS|Socket")
	float SocketExtensionOffset{ 40.f };

	UPROPERTY(EditAnywhere, Category = "SBS|Socket")
	float SphereTraceRadius{ 60.f };

	TArray<FHitResult> PerformSphereTrace(USkeletalMeshComponent* MeshComp) const;

	void SendEventsToActors(USkeletalMeshComponent* MeshComp, const TArray<FHitResult>& Hits) const;

};
