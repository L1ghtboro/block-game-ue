#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Voxel.generated.h"

UENUM(BlueprintType) enum class EVoxelType : uint8 {
	Dirt UMETA(DisplayName = "Dirt"),
	Grass UMETA(DisplayName = "Grass"),
	Stone UMETA(DisplayName = "Stone")
};

UCLASS() class MINECRAFT_API AVoxel : public AActor {
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVoxel();

	void SetVoxelType(EVoxelType VoxelType);

	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* VoxelMesh;

	UStaticMesh* DirtMesh;
	UStaticMesh* GrassMesh;
	UStaticMesh* StoneMesh;
};
