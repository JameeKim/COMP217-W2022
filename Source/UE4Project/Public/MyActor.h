// Dohyun Kim (301058465)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class UE4PROJECT_API AMyActor : public AActor
{
	GENERATED_BODY()

public:
	AMyActor();

	UPROPERTY(Category="Health", BlueprintReadWrite, EditAnywhere)
	int EnemyHealth;

	UPROPERTY(Category="Damage", BlueprintReadWrite, EditAnywhere)
	int Damage;

	UFUNCTION(Category="Action", BlueprintCallable)
	void Attack(int Power);

	UFUNCTION(Category="Action", BlueprintCallable)
	void FollowPlayer(float Speed);

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaSeconds) override;
};
