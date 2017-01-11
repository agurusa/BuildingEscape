// Copyright Aarthi Gurusami 2017

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;
    
    void OpenDoor();
    void CloseDoor();
    
private:
    UPROPERTY(EditAnywhere)
    float OpenAngle = 80.0f;
    //Why doesn't this work?
    //FRotator CloseAngle = GetOwner()->GetActorRotation();
    float CloseAngle = 0.0f;
    
    UPROPERTY(EditAnywhere)
    ATriggerVolume* PressurePlate;
    
    UPROPERTY(EditAnywhere)
    float DoorCloseDelay = 1.f;
    
    float LastDoorOpenTime;
    
    AActor* ActorThatOpens; //remember that pawn inherits from actor
    AActor* Owner; //The owning door
};
