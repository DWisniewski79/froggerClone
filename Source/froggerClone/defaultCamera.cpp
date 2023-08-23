// Fill out your copyright notice in the Description page of Project Settings.


#include "defaultCamera.h"
#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"



void AdefaultCamera::BeginPlay()
{
	FVector CamLoc;
	FVector CamLocTwo;
	FRotator CamRot;
	FRotator CamRotTwo;
	int x;
	int y;
	APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
	OurPlayerController->SetViewTarget(myCamera);
	OurPlayerController->GetPlayerViewPoint(CamLoc, CamRot);
	OurPlayerController->GetViewportSize(x, y);
	FVector CameraBounds;
	CameraBounds.Set((float)x, (float)y, CamLoc.Z);
	myCamera->GetActorEyesViewPoint(CamLocTwo, CamRotTwo);

	FVector ViewPos = OurPlayerController->GetFocalLocation();

	ViewPos.X = FMath::Clamp(ViewPos.X, CameraBounds.X, CameraBounds.X * -1);
	ViewPos.Y = FMath::Clamp(ViewPos.Y, CameraBounds.Y, CameraBounds.Y * -1);
	//OurPlayerController->SetActorLocation(ViewPos);

	UE_LOG(LogTemp, Warning, TEXT("x value: %d, y value: %d"), x,y);
	UE_LOG(LogTemp, Warning, TEXT("cameraLoc2: %s"), *CamLocTwo.ToString());
	UE_LOG(LogTemp, Warning, TEXT("camera bounds: %s"), *CameraBounds.ToString());
	UE_LOG(LogTemp, Warning, TEXT("Not sure what this will print: %s"), *ViewPos.ToString());

	
}
