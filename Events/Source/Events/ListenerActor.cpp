// Copyright A.T. Chamillard. All Rights Reserved.


#include "ListenerActor.h"

#include "Kismet/GameplayStatics.h"

/**
 * Sets default values
*/
AListenerActor::AListenerActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

/**
 * Called when the game starts or when spawned
*/
void AListenerActor::BeginPlay()
{
	Super::BeginPlay();

	// try to find Actor with tag
	TArray<AActor*> TaggedActors;
	UGameplayStatics::GetAllActorsWithTag(
		GetWorld(), "Talker", TaggedActors);

	// bind callback function to delegate
	if (TaggedActors.Num() > 0)
	{
		Talker = Cast<ATalkerActor>(
			TaggedActors[0]);
		DelegateHandle = Talker->MessageDelegate.AddUObject(this,
			&AListenerActor::ReceiveMessage);
	}
}

/**
 * Called every frame
*/
void AListenerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/**
 * Receives a message
 * @param Message the message
*/
void AListenerActor::ReceiveMessage(FString Message)
{
	UE_LOG(LogTemp, Warning, TEXT("Got Message: %s"),
		*Message);
}

/**
 * Called when actor is being removed from level
 * @param EndPlayReason why the actor is being removed
*/
void AListenerActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (Talker != nullptr)
	{
		Talker->MessageDelegate.Remove(DelegateHandle);
	}
}
