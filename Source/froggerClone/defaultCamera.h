// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "GameFramework/PlayerController.h"
#include "defaultCamera.generated.h"


/**
 * 
 */
UCLASS()
class FROGGERCLONE_API AdefaultCamera : public ACameraActor
{
	GENERATED_BODY()

private:
	UPROPERTY()
	ACameraActor* defaultCamera;

	USceneComponent* test;
	void setDefaultCameraViewpoint(ACameraActor*);
	void setDefaultCameraViewpoint(UCameraComponent*);
	

protected:

	virtual void BeginPlay() override;


public:
	UPROPERTY(EditAnywhere)
		AActor* myCamera;

	ACameraActor* getCamera(ACameraActor* defaultCamera);
};
