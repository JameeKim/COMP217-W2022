// Dohyun Kim (301058465)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Elevator.generated.h"

UCLASS()
class UE4PROJECT_API AElevator : public AActor
{
	GENERATED_BODY()

public:
	AElevator();

	UPROPERTY(Category="Elevator", BlueprintReadOnly, EditAnywhere)
	float Speed;

	UFUNCTION(Category="Elevator", BlueprintCallable)
	void MoveUp();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
