// Fill out your copyright notice in the Description page of Project Settings.


#include "spaceShip_CPP.h"
#include "PaperFlipbookComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/Pawn.h"
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
	if (Value == 0.0f)
	{
		return;
	}

	bool left = false;
	bool right = false;

	if (Value > inputThreshold)
	{
		right = true;
		UE_LOG(LogTemp, Warning, TEXT("value for right has been pressed"));
	}
	if (Value < -inputThreshold)
	{
		left = true;
		UE_LOG(LogTemp, Warning, TEXT("value for left has been pressed"))
	}

	if ((right && !left) || (!right && left))
	{
		Facing = 1;
	}

	if (left)
	{
		Facing = -1;
	}
	AddMovementInput(FVector(1.0f, 0.0f, 0.0f), Facing);
	UE_LOG(LogTemp, Warning, TEXT("movementinput received"))
		int count = 0;
	UE_LOG(LogTemp, Warning, TEXT("check to see if this is called without input %d"), count);
	count++;
}

void AspaceShip_CPP::VerticalMovement(float Value)
{
	// Move at 10 units per second forward or backward
	CurrentVelocity.Y = FMath::Clamp(Value, -1.0f, 1.0f) * 10.0f;
}

// Called to bind functionality to input
void AspaceShip_CPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	//Respond every frame to the values of the movement axes horizontal and vertical

	PlayerInputComponent->BindAxis("horizontal", this, &AspaceShip_CPP::HorizontalMovement);
	PlayerInputComponent->BindAxis("vertical", this, &AspaceShip_CPP::VerticalMovement);
}

