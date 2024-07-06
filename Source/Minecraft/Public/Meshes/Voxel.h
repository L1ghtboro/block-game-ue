#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Voxel.generated.h"

UCLASS() class MINECRAFT_API AVoxel : public AActor {
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVoxel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* VoxelMesh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
