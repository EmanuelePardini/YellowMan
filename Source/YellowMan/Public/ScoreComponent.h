// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ScoreComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class YELLOWMAN_API UScoreComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UScoreComponent();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int Score = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int EnemyKilled = 0;
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScoreChanged, int, Value);
	FOnScoreChanged OnScoreChanged;
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnemyKilledChanged, int, Value);
	FOnEnemyKilledChanged OnEnemyKilledChanged;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION()
	void Increment(int Value);
	void IncrementEnemyKilled(int Value);
};
