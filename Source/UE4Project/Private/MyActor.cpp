// Dohyun Kim (301058465)

#include "MyActor.h"

#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

AMyActor::AMyActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMyActor::Attack(int Power)
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Red, TEXT("Enemy attacks"));
}

void AMyActor::FollowPlayer(float Speed)
{
	const ACharacter* Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	SetActorLocation(Player->GetActorLocation(), false, nullptr, ETeleportType::None);
}

void AMyActor::BeginPlay()
{
	Super::BeginPlay();
}

void AMyActor::Tick(const float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}
