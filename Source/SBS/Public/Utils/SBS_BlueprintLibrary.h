// Copyright HeheKrazy

#pragma once

#include "CoreMinimal.h"

#include "InterchangeTranslatorBase.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SBS_BlueprintLibrary.generated.h"

UENUM(BlueprintType)
enum class EHitDirection :uint8
{
	Left,
	Right,
	Forward,
	Backward
};

USTRUCT(BlueprintType)
struct FClosestActorWithTagResult
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	TWeakObjectPtr<AActor> Actor;

	UPROPERTY(BlueprintReadWrite)
	float Distance{0.f};
};

UCLASS()
class SBS_API USBS_BlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintPure)
	static EHitDirection GetHitDirection(const FVector& TargetForward, const FVector& ToInstigator);

	UFUNCTION(BlueprintPure)
	static FName GetHitDirectionName(const EHitDirection HitDirection);

	UFUNCTION(BlueprintCallable)
	static FClosestActorWithTagResult FindClosestActorWithTag(const UObject* WorldContextObject, const FVector& Origin, const FName& Tag);
};
