// Copyright A.T. Chamillard. All Rights Reserved.


#include "TalkerActor.h"

/**
 * Sets default values
*/
ATalkerActor::ATalkerActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

/**
 * Called when the game starts or when spawned
*/
void ATalkerActor::BeginPlay()
{
	Super::BeginPlay();

	StartTalkerTimer();
}

/**
 * Called every frame
*/
void ATalkerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/**
 * Starts the talker timer
*/
void ATalkerActor::StartTalkerTimer()
{
	// start the timer
	FTimerHandle Timer;
	GetWorldTimerManager().SetTimer(Timer, this,
		&ATalkerActor::Talk, 3);
}

/**
 * Sends a message to listener
*/
void ATalkerActor::Talk()
{
	MessageDelegate.Broadcast(
		"Message " + FString::FromInt(MessageNumber));
	MessageNumber++;
	StartTalkerTimer();
}