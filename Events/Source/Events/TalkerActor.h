// Copyright A.T. Chamillard. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TalkerActor.generated.h"

DECLARE_EVENT_OneParam(ATalkerActor, FMessageDelegate, FString);

/**
 * A talker who sends a message through a delegate
*/
UCLASS()
class EVENTS_API ATalkerActor : public AActor
{
	GENERATED_BODY()
	
private:
	int MessageNumber{ 1 };

	/**
	 * Starts the talker timer
	*/
	void StartTalkerTimer();

	/**
	 * Sends a message to listener
	*/
	void Talk();

public:
	FMessageDelegate MessageDelegate;

	/**
	 * Sets default values for this actor's properties
	*/
	ATalkerActor();

protected:
	/**
	 * Called when the game starts or when spawned
	*/
	virtual void BeginPlay() override;

public:	
	/**
	 * Called every frame
	 * @param DeltaTime Game time elapsed during last frame modified by the time dilation 
	*/
	virtual void Tick(float DeltaTime) override;

};
