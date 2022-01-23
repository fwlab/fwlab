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
	libbackend
	libbluegl
	libbluevk
	libcamutils
	libcivetweb
	libdracodec
	libfilabridge
	libfilaflat
	libfilamat
	libfilamat_lite
	libfilament
	libfilament-iblprefilter
	libfilameshio
	libgeometry
	libgltfio
	libgltfio_core
	libgltfio_resources
	libgltfio_resources_lite
	libibl
	libibl-lite
	libimage
	libmatdbg
	libmeshoptimizer
	libshaders
	libsmol-v
	libutils
	libviewer
	libvkshaders
)

# sub_directories
add_subdirectory(assets)
link_libraries(
	fwlab_assets
)
add_subdirectory(src)