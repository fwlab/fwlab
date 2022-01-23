cmake_minimum_required(VERSION 3.19)

project(fwlab VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(FILAMENT_DIR ${CMAKE_SOURCE_DIR}/third_party/release/filament)

include_directories(
	${FILAMENT_DIR}/include
)

link_directories(
	${FILAMENT_DIR}/lib/x86_64
)

link_libraries(
	backend
	bluegl
	bluevk
	camutils
	civetweb
	dracodec
	filabridge
	filaflat
	filamat
	filamat_lite
	filament
	filament-iblprefilter
	filameshio
	geometry
	gltfio
	gltfio_core
	gltfio_resources
	gltfio_resources_lite
	ibl
	ibl-lite
	image
	matdbg
	meshoptimizer
	shaders
	smol-v
	utils
	viewer
	vkshaders
)

# sub_directories
add_subdirectory(assets)
link_libraries(
	fwlab_assets
)
add_subdirectory(src)