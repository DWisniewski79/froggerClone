// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "GameFramework/Character.h"
#include "spaceShip_CPP.generated.h"

UCLASS()
class FROGGERCLONE_API AspaceShip_CPP : public ACharacter
{
	GENERATED_UCLASS_BODY()

		//Name of Sprite component
		static FName SpriteComponentName;

public:
	/* The skeletal mesh for the sprite */
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UPaperFlipbookComponent* Sprite;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class USceneComponent* RotComp;

	
	/*Sprite Variables*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
		class UPaperFlipbook* IdleAnim;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
		class UPaperFlipbook* MoveAnim;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Animations)
		class UPaperFlipbook* DesiredAnim;

	/*End Sprite Variables*/

	/*States*/
	const int IDLE = 10;
	const int MOVE = 12;

	int STATE = IDLE;
	bool bNewState = true;

	int facing = 1;
	float inputThreshold = 0.4;
	/*End State*/

	// Sets default values for this character's properties
	AspaceShip_CPP();

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	void UpdateStates();
	void HorizontalMovement(float Value);
	void VerticalMovement(float Value);
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	/*Returns Sprite SubObject*/
	FORCEINLINE class UPaperFlipbookComponent* GetSprite() const {return Sprite;}
	FORCEINLINE class USceneComponent* GetRot() const { return RotComp; }
};
