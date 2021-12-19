cmake_minimum_required(VERSION 3.19)

project(fwlab VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_compile_options(
	$<$<CONFIG:>:/MT>
    $<$<CONFIG:Debug>:/MTd>
	$<$<CONFIG:Release>:/MT>
)

set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} /Z7")
set(CMAKE_C_FLAGS_RELWITHDEBINFO "${CMAKE_C_FLAGS_RELWITHDEBINFO} /Z7")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /Z7")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} /Z7")

set(CXX_STANDARD "/std:c++17")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_USE_MATH_DEFINES=1")

# third_party
set(FILAMENT_DIR ${CMAKE_SOURCE_DIR}/third_party/filament)
set(FILAMENT_OUT_DIR ${FILAMENT_DIR}/out/build/x64-Debug)

include_directories(
	# filament
	${FILAMENT_DIR}/filament/include
	${FILAMENT_DIR}/filament/backend/include
	# filament libs
	${FILAMENT_DIR}/libs/bluegl/include
	${FILAMENT_DIR}/libs/bluevk/include
	${FILAMENT_DIR}/libs/camutils/include
	${FILAMENT_DIR}/libs/filabridge/include
	${FILAMENT_DIR}/libs/filaflat/include
	${FILAMENT_DIR}/libs/filagui/include
	${FILAMENT_DIR}/libs/filamat/include
	${FILAMENT_DIR}/libs/filamentapp/include
	${FILAMENT_DIR}/libs/filameshio/include
	${FILAMENT_DIR}/libs/geometry/include
	${FILAMENT_DIR}/libs/gltfio/include
	${FILAMENT_DIR}/libs/ibl/include
	${FILAMENT_DIR}/libs/iblprefilter/include
	${FILAMENT_DIR}/libs/image/include
	${FILAMENT_DIR}/libs/imageio/include
	${FILAMENT_DIR}/libs/matdbg/include
	${FILAMENT_DIR}/libs/math/include
	${FILAMENT_DIR}/libs/mathio/include
	${FILAMENT_DIR}/libs/utils/include
	${FILAMENT_DIR}/libs/viewer/include
	# filament third_party
	${FILAMENT_DIR}/third_party/astcenc/include
	${FILAMENT_DIR}/third_party/benchmark/include
	${FILAMENT_DIR}/third_party/civetweb/include
	${FILAMENT_DIR}/third_party/getopt/include
	${FILAMENT_DIR}/third_party/imgui
	${FILAMENT_DIR}/third_party/libassimp/include
	${FILAMENT_DIR}/third_party/libpng
	${FILAMENT_DIR}/third_party/libsdl2/include
	${FILAMENT_DIR}/third_party/libz
	${FILAMENT_DIR}/third_party/spirv-cross/include
	${FILAMENT_DIR}/third_party/spirv-tools/include
	${FILAMENT_DIR}/third_party/vkmemalloc/include
	# filament samples
	${FILAMENT_DIR}/out/build/x64-Debug/samples
)

link_directories(
	# filament third_party
	${FILAMENT_OUT_DIR}/third_party/astcenc/tnt
	${FILAMENT_OUT_DIR}/third_party/benchmark/tnt
	${FILAMENT_OUT_DIR}/third_party/civetweb/tnt
	${FILAMENT_OUT_DIR}/third_party/draco/tnt
	${FILAMENT_OUT_DIR}/third_party/etc2comp/EtcLib
	${FILAMENT_OUT_DIR}/third_party/getopt
	${FILAMENT_OUT_DIR}/third_party/glslang/tnt/glslang
	${FILAMENT_OUT_DIR}/third_party/glslang/tnt/glslang/OSDependent/Windows
	${FILAMENT_OUT_DIR}/third_party/glslang/tnt/OGLCompilersDLL
	${FILAMENT_OUT_DIR}/third_party/glslang/tnt/SPIRV
	${FILAMENT_OUT_DIR}/third_party/imgui/tnt
	${FILAMENT_OUT_DIR}/third_party/libassimp/tnt
	${FILAMENT_OUT_DIR}/third_party/libgtest/tnt
	${FILAMENT_OUT_DIR}/third_party/libpng/tnt
	${FILAMENT_OUT_DIR}/third_party/libsdl2/tnt
	${FILAMENT_OUT_DIR}/third_party/libz/tnt
	${FILAMENT_OUT_DIR}/third_party/meshoptimizer
	${FILAMENT_OUT_DIR}/third_party/smol-v/tnt
	${FILAMENT_OUT_DIR}/third_party/spirv-cross/tnt
	${FILAMENT_OUT_DIR}/third_party/spirv-tools/source
	${FILAMENT_OUT_DIR}/third_party/tinyexr/tnt
	# filament
	${FILAMENT_OUT_DIR}/filament
	${FILAMENT_OUT_DIR}/filament/backend
	# filament libs
	${FILAMENT_OUT_DIR}/libs/bluegl
	${FILAMENT_OUT_DIR}/libs/camutils
	${FILAMENT_OUT_DIR}/libs/filabridge
	${FILAMENT_OUT_DIR}/libs/filaflat
	${FILAMENT_OUT_DIR}/libs/filagui
	${FILAMENT_OUT_DIR}/libs/filamat
	${FILAMENT_OUT_DIR}/libs/filamentapp
	${FILAMENT_OUT_DIR}/libs/filameshio
	${FILAMENT_OUT_DIR}/libs/geometry
	${FILAMENT_OUT_DIR}/libs/gltfio
	${FILAMENT_OUT_DIR}/libs/ibl
	${FILAMENT_OUT_DIR}/libs/iblprefilter
	${FILAMENT_OUT_DIR}/libs/image
	${FILAMENT_OUT_DIR}/libs/imageio
	${FILAMENT_OUT_DIR}/libs/matdbg
	${FILAMENT_OUT_DIR}/libs/math
	${FILAMENT_OUT_DIR}/libs/mathio
	${FILAMENT_OUT_DIR}/libs/utils
	${FILAMENT_OUT_DIR}/libs/viewer
	# filament samples
	${FILAMENT_DIR}/out/build/x64-Debug/samples
)

link_libraries(
	# windows
	IMM32.lib
	shlwapi.lib
	winmm.lib
	Version.lib
	Opengl32.lib
	# filament third_party
	astcenc.lib
	benchmark.lib
	benchmark_main.lib
	civetweb.lib
	dracodec.lib
	EtcLib.lib
	getopt.lib
	glslangd.lib
	OSDependentd.lib
	OGLCompilerd.lib
	SPIRVd.lib
	SPVRemapperd.lib
	imgui.lib
	assimp.lib
	gtest.lib
	png.lib
	sdl2.lib
	sdl2main.lib
	z.lib
	meshoptimizer.lib
	smol-v.lib
	spirv-cross-core.lib
	spirv-cross-glsl.lib
	spirv-cross-msl.lib
	SPIRV-Tools.lib
	tinyexr.lib
	# filament
	filament.lib
	backend.lib
	vkshaders.lib
	# filament libs
	bluegl.lib
	camutils.lib
	filabridge.lib
	filaflat.lib
	filagui.lib
	filamat.lib
	filamentapp.lib
	filamentapp-resources.lib
	filameshio.lib
	geometry.lib
	gltfio.lib
	ibl.lib
	filament-iblprefilter.lib
	image.lib
	imageio.lib
	matdbg.lib
	matdbg_resources.lib
	math.lib
	mathio.lib
	utils.lib
	viewer.lib
	# filament samples
	# sample-resources.lib
)

# sub_directories
add_subdirectory(assets)
link_libraries(
	fwlab_assets
)
add_subdirectory(src)