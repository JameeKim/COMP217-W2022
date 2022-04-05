// Dohyun Kim (301058465)

#include "Elevator.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
AElevator::AElevator()
{
	Speed = 50.0f;
	PrimaryActorTick.bCanEverTick = true;
}

void AElevator::MoveUp()
{
	FVector location = GetActorLocation();
	location.Z += Speed * UGameplayStatics::GetWorldDeltaSeconds(GetWorld());
	SetActorLocation(location);
}

void AElevator::BeginPlay()
{
	Super::BeginPlay();
}

void AElevator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
