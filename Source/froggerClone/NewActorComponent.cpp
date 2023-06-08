// Fill out your copyright notice in the Description page of Project Settings.


#include "NewActorComponent.h"
#include "defaultCamera.h"


AdefaultCamera* camera;

// Sets default values for this component's properties
UNewActorComponent::UNewActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}


// Called when the game starts
void UNewActorComponent::BeginPlay()
{
	Super::BeginPlay();
	camera->getCamera(camera);
	
	
}


// Called every frame
void UNewActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}



UNewActorComponent*::getPlayer(UNewActorComponent* player) { return player; };