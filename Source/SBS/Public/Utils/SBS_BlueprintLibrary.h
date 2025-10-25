// Copyright HeheKrazy

#pragma once

#include "CoreMinimal.h"
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

UCLASS()
class SBS_API USBS_BlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintPure)
	static EHitDirection GetHitDirection(const FVector& TargetForward, const FVector& ToInstigator);

	UFUNCTION(BlueprintPure)
	static FName GetHitDirectionName(const EHitDirection HitDirection);
};
