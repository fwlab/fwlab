cmake_minimum_required(VERSION 3.19)

project(fwlab VERSION 0.0.1)

if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.12")
    cmake_policy(SET CMP0074 NEW)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CXX_STANDARD "-std=c++20")
if (WIN32)
    set(CXX_STANDARD "/std:c++20")
endif()

if (MSVC)
    set(CXX_STANDARD "/std:c++latest")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_STANDARD} /W0 /Zc:__cplusplus")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_STANDARD} -fstrict-aliasing -Wno-unknown-pragmas -Wno-unused-function")
endif()
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(FILAMENT_DIR "${CMAKE_SOURCE_DIR}/third_party/filament")
set(RELEASE_DIR "${FILAMENT_DIR}/out/build")
set(INSTALL_DIR "${FILAMENT_DIR}/out/install")
set(RAPID_JSON_DIR "${CMAKE_SOURCE_DIR}/third_party/rapidjson")
set(BULLET3_DIR "${CMAKE_SOURCE_DIR}/third_party/bullet3")
#set(OCCT_DIR "${CMAKE_SOURCE_DIR}/third_party/OCCT/out/install")

if (WIN32)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8")
	set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
	
	add_compile_options(
		$<$<CONFIG:>:/MT>
		$<$<CONFIG:Debug>:/MTd>
		$<$<CONFIG:Release>:/MT>
	)
	
	set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} /Z7")
    set(CMAKE_C_FLAGS_RELWITHDEBINFO "${CMAKE_C_FLAGS_RELWITHDEBINFO} /Z7")

	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Zi")
    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} /Zi")

	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /Z7")
	set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} /Z7")
else ()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -stdlib=libc++")
endif()

if (MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_CRT_SECURE_NO_WARNINGS -D_CRT_NONSTDC_NO_DEPRECATE")
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_CRT_SECURE_NO_WARNINGS -D_CRT_NONSTDC_NO_DEPRECATE")
endif()

set(B_SYMBOLIC_FUNCTIONS "-Wl,-Bsymbolic-functions")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GC_SECTIONS}")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} ${GC_SECTIONS} ${B_SYMBOLIC_FUNCTIONS}")

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

	# filament
	${INSTALL_DIR}/include

	# libs
	${FILAMENT_DIR}/libs/bluegl/include
	${FILAMENT_DIR}/libs/filabridge/include
	${FILAMENT_DIR}/libs/filaflat/include
	${FILAMENT_DIR}/libs/filagui/include
	#${FILAMENT_DIR}/libs/filamentapp/include
	${FILAMENT_DIR}/libs/iblprefilter/include
	${FILAMENT_DIR}/libs/imageio/include
	${FILAMENT_DIR}/libs/matdbg/include

	# rapidjson
	${RAPID_JSON_DIR}/include

	# bullet3
	${BULLET3_DIR}/out/install/include

	# OCCT
	#${OCCT_DIR}/inc

	# asserts
	${CMAKE_BINARY_DIR}/assets
)

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

	# bullet3
	${BULLET3_DIR}/out/install/lib
)

if (WIN32)
	link_directories(
		# third_party
		${RELEASE_DIR}/third_party/glslang/tnt/glslang/OSDependent/Windows
		# OCCT
		#${OCCT_DIR}/win64/vc14/libd
	)
	link_libraries(
		IMM32.lib
		shlwapi.lib
		winmm.lib
		Version.lib
		Opengl32.lib
	)
else ()
	link_directories(
		# third_party
		${RELEASE_DIR}/third_party/glslang/tnt/glslang/OSDependent/Unix
	)
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
	#benchmark
	#benchmark_main
	civetweb
	dracodec
	EtcLib
	getopt
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
	math
	mathio
	utils
	viewer

	# OCCT
	#TKBin
	#TKBinL
	#TKBinTObj
	#TKBinXCAF
	#TKBO
	#TKBool
	#TKBRep
	#TKCAF
	#TKCDF
	#TKernel
	#TKFeat
	#TKFillet
	#TKG2d
	#TKG3d
	#TKGeomAlgo
	#TKGeomBase
	#TKHLR
	#TKIGES
	#TKLCAF
	#TKMath
	#TKMesh
	#TKOffset
	#TKPrim
	#TKRWMesh
	#TKService
	#TKShHealing
	#TKStd
	#TKStdL
	#TKSTEP
	#TKSTEP209
	#TKSTEPAttr
	#TKSTEPBase
	#TKSTL
	#TKTObj
	#TKTopAlgo
	#TKV3d
	#TKVCAF
	#TKVRML
	#TKXCAF
	#TKXDEIGES
	#TKXDESTEP
	#TKXMesh
	#TKXml
	#TKXmlL
	#TKXmlTObj
	#TKXmlXCAF
	#TKXSBase
)

if (WIN32)
	if ("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
		link_libraries(
			# third_party
			glslangd
			OSDependentd
			OGLCompilerd
			SPIRVd
			SPVRemapperd
			
			# libs
			#matdbg_combined

			# bullet3
			BulletRobotics_Debug
			BussIK_Debug
			clsocket_Debug
			gwen_Debug
		)
	else()
		link_libraries(
			# third_party
			glslang
			OSDependent
			OGLCompiler
			SPIRV
			SPVRemapper
			
			# libs
			#matdbg_combined
		)
	endif()
else ()
	link_libraries(
		# third_party
		glslang
		OSDependent
		OGLCompiler
		SPIRV
		#SPVRemapper

		# libs
		matdbg_combined
	)
endif()

# sub_directories
add_subdirectory(assets)

link_libraries(
	fwlab_assets
)

add_subdirectory(src)

# install
install(FILES "${CMAKE_BINARY_DIR}/fwlab.exe" DESTINATION "${CMAKE_INSTALL_PREFIX}")