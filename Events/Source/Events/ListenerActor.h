// Copyright A.T. Chamillard. All Rights Reserved.

#pragma once

#include "TalkerActor.h"
#include "Engine/EngineTypes.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ListenerActor.generated.h"

/**
 * A listener that provides a cllback function to get messages
*/
UCLASS()
class EVENTS_API AListenerActor : public AActor
{
	GENERATED_BODY()
	
private:
	ATalkerActor* Talker;
	FDelegateHandle DelegateHandle;

public:	
	/**
	 * Sets default values for this actor's properties
	*/
	AListenerActor();

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

	/**
	 * Receives a message
	 * @param Message the message
	*/
	UFUNCTION()
		void ReceiveMessage(FString Message);

	/**
	 * Called when actor is being removed from level
	 * @param EndPlayReason why the actor is being removed
	*/
	UFUNCTION()
		virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
