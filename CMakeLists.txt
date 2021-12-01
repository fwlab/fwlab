cmake_minimum_required(VERSION 3.19)

project(fwlab VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (WIN32)
    # Link statically against c/c++ lib to avoid missing redistriburable such as
    # "VCRUNTIME140.dll not found. Try reinstalling the app.", but give users
    # a choice to opt for the shared runtime if they want.
    option(USE_STATIC_CRT "Link against the static runtime libraries." ON)

    # On Windows we need to instruct cmake to generate the .def in order to get the .lib required
    # when linking against dlls. CL.EXE will not generate .lib without .def file (or without pragma
    # __declspec(dllexport) in front of each functions).
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

    # The CMAKE_CXX_FLAGS vars can be overriden by some Visual Studio generators, so we use an alternative
    # global method here:
    if (${USE_STATIC_CRT})
        add_compile_options(
            $<$<CONFIG:>:/MT>
            $<$<CONFIG:Debug>:/MTd>
            $<$<CONFIG:Release>:/MT>
        )
    else()
        add_compile_options(
            $<$<CONFIG:>:/MD>
            $<$<CONFIG:Debug>:/MDd>
            $<$<CONFIG:Release>:/MD>
        )
    endif()

    # TODO: Figure out why pdb generation messes with incremental compilaton.
    # IN RELEASE_WITH_DEBUG_INFO, generate debug info in .obj, no in pdb.
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} /Z7")
    set(CMAKE_C_FLAGS_RELWITHDEBINFO "${CMAKE_C_FLAGS_RELWITHDEBINFO} /Z7")

    # In RELEASE, also generate PDBs.
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Zi")
    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} /Zi")

    # In DEBUG, avoid generating a PDB file which seems to mess with incremental compilation.
    # Instead generate debug info directly inside obj files.
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /Z7")
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} /Z7")

    # Special settings when building on CI.
    if (${FILAMENT_WINDOWS_CI_BUILD})
        set(LinkerFlags
            CMAKE_SHARED_LINKER_FLAGS_DEBUG
            CMAKE_EXE_LINKER_FLAGS_DEBUG
            CMAKE_MODULE_LINKER_FLAGS_DEBUG
            )
        foreach(LinkerFlag ${LinkerFlags})
            # The /debug flag outputs .pdb files, which we don't need on CI.
            string(REPLACE "/debug" "" ${LinkerFlag} ${${LinkerFlag}})

            # The /INCREMENTAL flag outputs .ilk files for incremental linking. These are huge, and
            # we don't need them on CI.
            string(REPLACE "/INCREMENTAL" "/INCREMENTAL:NO" ${LinkerFlag} ${${LinkerFlag}})
        endforeach()
    endif()
endif()

if (WIN32)
    set(CXX_STANDARD "/std:c++17")
endif()

if (WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_USE_MATH_DEFINES=1")
endif()

set(FILAMENT_DIR ${CMAKE_SOURCE_DIR}/third_party/filament)

include_directories(
	# filament
	${FILAMENT_DIR}/filament/include
	${FILAMENT_DIR}/filament/backend/include

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

	${CMAKE_BINARY_DIR}/third_party/filament/samples
)

add_subdirectory(third_party)
add_subdirectory(src)