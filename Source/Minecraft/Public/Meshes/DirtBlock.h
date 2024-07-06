#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DirtBlock.generated.h"

UCLASS() class MINECRAFT_API ADirtBlock : public AActor {
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADirtBlock();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Generatable Blocks")
	UStaticMeshComponent* DirtBlockMesh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
