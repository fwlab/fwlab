cmake_minimum_required(VERSION 3.19)

project(fwlab VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(FILAMENT_DIR ${CMAKE_SOURCE_DIR}/third_party/filament)

include_directories(
	# third_party
	${FILAMENT_DIR}/third_party/imgui
	${FILAMENT_DIR}/third_party/libsdl2/include
	${FILAMENT_DIR}/third_party/stb
	# filament
	${FILAMENT_DIR}/out/release/filament/include
	${FILAMENT_DIR}/libs/filamentapp/include
)

link_directories(
	# third_party
	${FILAMENT_DIR}/out/cmake-release/third_party/astcenc/tnt
	${FILAMENT_DIR}/out/cmake-release/third_party/benchmark/tnt
	${FILAMENT_DIR}/out/cmake-release/third_party/civetweb/tnt
	${FILAMENT_DIR}/out/cmake-release/third_party/draco/tnt
	${FILAMENT_DIR}/out/cmake-release/third_party/etc2comp/EtcLib
	${FILAMENT_DIR}/out/cmake-release/third_party/getopt
	${FILAMENT_DIR}/out/cmake-release/third_party/glslang/tnt/glslang
	${FILAMENT_DIR}/out/cmake-release/third_party/glslang/tnt/OGLCompilersDLL
	${FILAMENT_DIR}/out/cmake-release/third_party/glslang/tnt/SPIRV
	${FILAMENT_DIR}/out/cmake-release/third_party/imgui/tnt
	${FILAMENT_DIR}/out/cmake-release/third_party/libassimp/tnt
	${FILAMENT_DIR}/out/cmake-release/third_party/libgtest/tnt
	${FILAMENT_DIR}/out/cmake-release/third_party/libpng/tnt
	${FILAMENT_DIR}/out/cmake-release/third_party/libsdl2/tnt
	${FILAMENT_DIR}/out/cmake-release/third_party/libz/tnt
	${FILAMENT_DIR}/out/cmake-release/third_party/meshoptimizer
	${FILAMENT_DIR}/out/cmake-release/third_party/smol-v/tnt
	${FILAMENT_DIR}/out/cmake-release/third_party/spirv-cross/tnt
	${FILAMENT_DIR}/out/cmake-release/third_party/spirv-tools/source
	${FILAMENT_DIR}/out/cmake-release/third_party/spirv-tools/source/link
	${FILAMENT_DIR}/out/cmake-release/third_party/spirv-tools/source/lint
	${FILAMENT_DIR}/out/cmake-release/third_party/spirv-tools/source/opt
	${FILAMENT_DIR}/out/cmake-release/third_party/spirv-tools/source/reduce
	${FILAMENT_DIR}/out/cmake-release/third_party/tinyexr/tnt

	# filament
	${FILAMENT_DIR}/out/release/filament/lib/x86_64
	${FILAMENT_DIR}/out/cmake-release/libs/filamentapp
)

link_libraries(
	c++
	c++abi
	pthread
	# third_party
	astcenc
	benchmark
	#benchmark_main
	civetweb
	dracodec
	EtcLib
	getopt
	glslang
	OGLCompiler
	SPIRV
	#SPVRemapper
	imgui
	assimp
	gtest
	png
	sdl2
	z
	meshoptimizer
	smol-v
	spirv-cross-core
	spirv-cross-glsl
	spirv-cross-msl
	SPIRV-Tools
	SPIRV-Tools-link
	SPIRV-Tools-lint
	SPIRV-Tools-opt
	SPIRV-Tools-reduce
	tinyexr

	# filament
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
	filamentapp
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