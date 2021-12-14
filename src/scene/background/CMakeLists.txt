set(MODULE_NAME fwlab_scene_background)

set(GENERATED_DIR ${CMAKE_CURRENT_BINARY_DIR}/generated)

add_custom_command(
	OUTPUT ${GENERATED_DIR}/resources/resources.c
	COMMAND resgen -c --deploy=${GENERATED_DIR}/resources ${CMAKE_CURRENT_SOURCE_DIR}/ibl_river_roughness_m0.png
)

include_directories(
	${GENERATED_DIR}
)

add_library(${MODULE_NAME} STATIC
	"Scene.cpp" "${GENERATED_DIR}/resources/resources.c"
)

target_link_libraries(${MODULE_NAME}
	filament filamentapp
	fwlab_object
)
