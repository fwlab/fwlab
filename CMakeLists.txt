cmake_minimum_required(VERSION 3.19)

project(fwlab VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(FILAMENT_DIR ${CMAKE_SOURCE_DIR}/third_party/filament)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -stdlib=libc++")

add_definitions(
	-DFILAMENT_SUPPORTS_X11
	-D_USE_MATH_DEFINES
	-DFILAMENT_SUPPORTS_OPENGL
	-DSTDC_HEADERS
	-DHAVE_SYS_TYPES_H
	-DHAVE_STDLIB_H
	-DHAVE_STRING_H
	-DHAVE_MATH_H
)

include_directories(
	# third_party
	${FILAMENT_DIR}/third_party/imgui
	${FILAMENT_DIR}/third_party/libsdl2/include
	${FILAMENT_DIR}/third_party/stb

	# filament
	${FILAMENT_DIR}/out/release/filament/include

	# libs
	${FILAMENT_DIR}/libs/bluegl/include
	${FILAMENT_DIR}/libs/filabridge/include
	${FILAMENT_DIR}/libs/filaflat/include
	${FILAMENT_DIR}/libs/filagui/include
	#${FILAMENT_DIR}/libs/filamentapp/include
	${FILAMENT_DIR}/libs/iblprefilter/include
	${FILAMENT_DIR}/libs/imageio/include
	${FILAMENT_DIR}/libs/matdbg/include

	# asserts
	${CMAKE_BINARY_DIR}/assets
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
	${FILAMENT_DIR}/out/cmake-release/filament
	${FILAMENT_DIR}/out/cmake-release/filament/backend
	${FILAMENT_DIR}/out/cmake-release/shaders

	# libs
	${FILAMENT_DIR}/out/cmake-release/libs/bluegl
	${FILAMENT_DIR}/out/cmake-release/libs/bluevk
	${FILAMENT_DIR}/out/cmake-release/libs/camutils
	${FILAMENT_DIR}/out/cmake-release/libs/filabridge
	${FILAMENT_DIR}/out/cmake-release/libs/filaflat
	${FILAMENT_DIR}/out/cmake-release/libs/filagui
	${FILAMENT_DIR}/out/cmake-release/libs/filamat
	${FILAMENT_DIR}/out/cmake-release/libs/filamentapp
	${FILAMENT_DIR}/out/cmake-release/libs/filameshio
	${FILAMENT_DIR}/out/cmake-release/libs/geometry
	${FILAMENT_DIR}/out/cmake-release/libs/gltfio
	${FILAMENT_DIR}/out/cmake-release/libs/ibl
	${FILAMENT_DIR}/out/cmake-release/libs/iblprefilter
	${FILAMENT_DIR}/out/cmake-release/libs/image
	${FILAMENT_DIR}/out/cmake-release/libs/imageio
	${FILAMENT_DIR}/out/cmake-release/libs/matdbg
	${FILAMENT_DIR}/out/cmake-release/libs/math
	${FILAMENT_DIR}/out/cmake-release/libs/mathio
	${FILAMENT_DIR}/out/cmake-release/libs/utils
	${FILAMENT_DIR}/out/cmake-release/libs/viewer
)

link_libraries(
	-static-libgcc
	-static-libstdc++
	c++
	c++abi
	pthread
	-ldl

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
	filaflat

	# filament
	filament
	backend
	vkshaders
	shaders

	# libs
	bluegl
	#bluevk
	camutils
	filabridge
	filagui
	filamat
	filamat_lite
	filamentapp
	filamentapp-resources
	filameshio
	geometry
	gltfio
	gltfio_core
	gltfio_resources
	gltfio_resources_lite
	ibl
	ibl-lite
	filament-iblprefilter
	image
	imageio
	matdbg
	matdbg_resources
	matdbg_combined
	math
	mathio
	utils
	viewer
)

# sub_directories
add_subdirectory(assets)

link_libraries(
	fwlab_assets
)

add_subdirectory(src)