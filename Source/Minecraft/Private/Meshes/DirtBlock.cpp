#include "Meshes/DirtBlock.h"

// Sets default values
ADirtBlock::ADirtBlock() : DirtBlockMesh(CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DirtBlockMesh"))) {
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	DirtBlockMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ADirtBlock::BeginPlay() {
	Super::BeginPlay();
	
}

// Called every frame
void ADirtBlock::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}

