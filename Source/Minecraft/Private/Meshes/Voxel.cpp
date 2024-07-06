#include "Meshes/Voxel.h"

// Sets default values
AVoxel::AVoxel() : VoxelMesh(CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VoxelMesh"))) {
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = VoxelMesh;

    // Correct path to the static mesh asset
    static ConstructorHelpers::FObjectFinder<UStaticMesh> VoxelAsset(TEXT("/Game/Meshes/DirtBlock.DirtBlock"));
    if (VoxelAsset.Succeeded()) {
        VoxelMesh->SetStaticMesh(VoxelAsset.Object);

        // Set the scale of the static mesh
        FVector NewScale(0.25f, 0.25f, 0.25f);  // Adjust the scale as needed
        VoxelMesh->SetWorldScale3D(NewScale);
    }
}

// Called when the game starts or when spawned
void AVoxel::BeginPlay() {
	Super::BeginPlay();
	
}

// Called every frame
void AVoxel::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}
//A:/Unreal Projects/Minecraft/Content/Meshes/DirtBlock.uasset
///Script/Engine.StaticMesh'/Game/Meshes/DirtBlock.DirtBlock'