// Fill out your copyright notice in the Description page of Project Settings.


#include "spaceShip_CPP.h"
#include "PaperFlipbookComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"

FName AspaceShip_CPP::SpriteComponentName(TEXT("Sprite0"));
// Sets default values
AspaceShip_CPP::AspaceShip_CPP(const FObjectInitializer& ObjectInitializer)
:Super(ObjectInitializer.DoNotCreateDefaultSubobject(ACharacter::MeshComponentName))
{
	//Try to create the sprite component
	Sprite = CreateOptionalDefaultSubobject<UPaperFlipbookComponent>(AspaceShip_CPP::SpriteComponentName);

	if (Sprite)
	{
		Sprite->AlwaysLoadOnClient = true;
		Sprite->AlwaysLoadOnServer = true;
		Sprite->bOwnerNoSee = false;
		Sprite->bAffectDynamicIndirectLighting = true;
		Sprite->PrimaryComponentTick.TickGroup = TG_PrePhysics;
		Sprite->SetupAttachment(GetCapsuleComponent());
		static FName CollisionProfileName(TEXT("CharacterMesh"));
		Sprite->SetCollisionProfileName(CollisionProfileName);
		Sprite->SetGenerateOverlapEvents(false);
		Sprite->SetFlipbook(IdleAnim);
	}

	//Set up Class' components
	RotComp = CreateDefaultSubobject<USceneComponent>(TEXT("RotatorComp"));
	RotComp->SetupAttachment(RootComponent);
	
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->SetPlaneConstraintNormal(FVector(-1.0f, 0.0f, 0.0f));
	GetCharacterMovement()->bOrientRotationToMovement = false;
	GetCharacterMovement()->bUseFlatBaseForFloorChecks = true;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	

}

// Called when the game starts or when spawned
void AspaceShip_CPP::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AspaceShip_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AspaceShip_CPP::UpdateStates()
{

}

void AspaceShip_CPP::HorizontalMovement(float Value)
{

}

void AspaceShip_CPP::VerticalMovement(float Value)
{

}

// Called to bind functionality to input
void AspaceShip_CPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//PlayerInputComponent->BindAxis("horizontal", IE_Pressed, this, &AspaceShip_CPP::HorizontalMovement);
}

