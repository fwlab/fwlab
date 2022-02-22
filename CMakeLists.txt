cmake_minimum_required(VERSION 3.19)

project(fwlab VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(FILAMENT_DIR ${CMAKE_SOURCE_DIR}/third_party/filament)

if (WIN32)
	set(RELEASE_DIR ${FILAMENT_DIR}/out/build/x64-Debug)
	set(INSTALL_DIR ${FILAMENT_DIR}/out/install/x64-Debug)
else ()
	set(RELEASE_DIR ${FILAMENT_DIR}/out/cmake-release)
	set(INSTALL_DIR ${FILAMENT_DIR}/out/release)
endif()

if (WIN32)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8")
else ()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -stdlib=libc++")
endif()

if (WIN32)
	add_definitions(
		-D_USE_MATH_DEFINES
		-DFILAMENT_SUPPORTS_OPENGL
		-DSTDC_HEADERS
		-DHAVE_SYS_TYPES_H
		-DHAVE_STDLIB_H
		-DHAVE_STRING_H
		-DHAVE_MATH_H
	)
else ()
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
endif()

include_directories(
	# third_party
	${FILAMENT_DIR}/third_party/imgui
	${FILAMENT_DIR}/third_party/libsdl2/include
	${FILAMENT_DIR}/third_party/stb

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

if (WIN32)
	include_directories(
		# filament
		${INSTALL_DIR}/include
	)
else ()
	include_directories(
		# filament
		${INSTALL_DIR}/filament/include
	)
endif ()

link_directories(
	# third_party
	${RELEASE_DIR}/third_party/astcenc/tnt
	${RELEASE_DIR}/third_party/benchmark/tnt
	${RELEASE_DIR}/third_party/civetweb/tnt
	${RELEASE_DIR}/third_party/draco/tnt
	${RELEASE_DIR}/third_party/etc2comp/EtcLib
	${RELEASE_DIR}/third_party/getopt
	${RELEASE_DIR}/third_party/glslang/tnt/glslang
	${RELEASE_DIR}/third_party/glslang/tnt/OGLCompilersDLL
	${RELEASE_DIR}/third_party/glslang/tnt/SPIRV
	${RELEASE_DIR}/third_party/imgui/tnt
	${RELEASE_DIR}/third_party/libassimp/tnt
	${RELEASE_DIR}/third_party/libgtest/tnt
	${RELEASE_DIR}/third_party/libpng/tnt
	${RELEASE_DIR}/third_party/libsdl2/tnt
	${RELEASE_DIR}/third_party/libz/tnt
	${RELEASE_DIR}/third_party/meshoptimizer
	${RELEASE_DIR}/third_party/smol-v/tnt
	${RELEASE_DIR}/third_party/spirv-cross/tnt
	${RELEASE_DIR}/third_party/spirv-tools/source
	${RELEASE_DIR}/third_party/spirv-tools/source/link
	${RELEASE_DIR}/third_party/spirv-tools/source/lint
	${RELEASE_DIR}/third_party/spirv-tools/source/opt
	${RELEASE_DIR}/third_party/spirv-tools/source/reduce
	${RELEASE_DIR}/third_party/tinyexr/tnt

	# filament
	${RELEASE_DIR}/filament
	${RELEASE_DIR}/filament/backend
	${RELEASE_DIR}/shaders

	# libs
	${RELEASE_DIR}/libs/bluegl
	${RELEASE_DIR}/libs/bluevk
	${RELEASE_DIR}/libs/camutils
	${RELEASE_DIR}/libs/filabridge
	${RELEASE_DIR}/libs/filaflat
	${RELEASE_DIR}/libs/filagui
	${RELEASE_DIR}/libs/filamat
	${RELEASE_DIR}/libs/filamentapp
	${RELEASE_DIR}/libs/filameshio
	${RELEASE_DIR}/libs/geometry
	${RELEASE_DIR}/libs/gltfio
	${RELEASE_DIR}/libs/ibl
	${RELEASE_DIR}/libs/iblprefilter
	${RELEASE_DIR}/libs/image
	${RELEASE_DIR}/libs/imageio
	${RELEASE_DIR}/libs/matdbg
	${RELEASE_DIR}/libs/math
	${RELEASE_DIR}/libs/mathio
	${RELEASE_DIR}/libs/utils
	${RELEASE_DIR}/libs/viewer
)

if (LINUX)
	link_libraries(
		-static-libgcc
		-static-libstdc++
		c++
		c++abi
		pthread
		-ldl
	)
endif()

link_libraries(
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