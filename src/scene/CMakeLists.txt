set(MODULE_NAME fwlab_scene)

set(GENERATED_DIR ${CMAKE_CURRENT_BINARY_DIR}/generated)

add_custom_command(
	OUTPUT ${GENERATED_DIR}/material/defaultMaterial.filamat
	COMMAND matc -o ${GENERATED_DIR}/material/defaultMaterial.filamat ${CMAKE_CURRENT_SOURCE_DIR}/materials/defaultMaterial.mat
)

add_custom_command(
	OUTPUT ${GENERATED_DIR}/resources/resources.c
	COMMAND resgen -c --deploy=${GENERATED_DIR}/resources ${GENERATED_DIR}/material/defaultMaterial.filamat
	DEPENDS ${GENERATED_DIR}/material/defaultMaterial.filamat
)

include_directories(
	${GENERATED_DIR}
)

add_library(${MODULE_NAME} STATIC
	"Scene.cpp" "${GENERATED_DIR}/resources/resources.c"
)

target_link_libraries(${MODULE_NAME}
	filament filamentapp sample-resources gltfio_core viewer
	fwlab_camera fwlab_object
)
