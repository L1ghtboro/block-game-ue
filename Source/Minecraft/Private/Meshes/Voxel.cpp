#include "Meshes/Voxel.h"

// Sets default values
AVoxel::AVoxel() : VoxelMesh(CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VoxelMesh"))) {
    // Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    RootComponent = VoxelMesh;
}

void AVoxel::SetVoxelType(EVoxelType VoxelType) {
    switch (VoxelType) {
    case EVoxelType::Dirt:
        VoxelMesh->SetStaticMesh(DirtMesh);
        break;
    case EVoxelType::Grass:
        VoxelMesh->SetStaticMesh(GrassMesh);
        break;
    case EVoxelType::Stone:
        VoxelMesh->SetStaticMesh(StoneMesh);
        break;
    default:
        break;
    }

    FVector NewScale(0.5f, 0.5f, 0.5f);
    VoxelMesh->SetWorldScale3D(NewScale);
}

// Called when the game starts or when spawned
void AVoxel::BeginPlay() {
    Super::BeginPlay();

    // Load assets here using StaticLoadObject
    DirtMesh = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), nullptr, TEXT("/Game/Meshes/DirtBlock.DirtBlock")));
    GrassMesh = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), nullptr, TEXT("/Game/Meshes/GrassBlock.GrassBlock")));
    StoneMesh = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), nullptr, TEXT("/Game/Meshes/StoneBlock.StoneBlock")));

    if (!DirtMesh || !GrassMesh || !StoneMesh) {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Failed to load one or more voxel meshes!"));
    }
}

// Called every frame
void AVoxel::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);
}