// Fill out your copyright notice in the Description page of Project Settings.


#include "defaultCamera.h"
#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"



void AdefaultCamera::BeginPlay()
{
	APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
	OurPlayerController->SetViewTarget(myCamera);
}
