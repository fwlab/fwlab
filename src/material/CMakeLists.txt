set(MODULE_NAME fwlab_material)

set(ASSETS_DIR "${CMAKE_CURRENT_BINARY_DIR}/generated")
set(RESOURCE_BINS)

# materials: mat -> filamat
set(MATERIAL_SRCS
	"mat/lit.mat"
	"mat/subsurface.mat"
	"mat/cloth.mat"
	"mat/unlit.mat"
	"mat/specular_glossiness.mat"
)

foreach (mat_src ${MATERIAL_SRCS})
	get_filename_component(filename "${mat_src}" NAME_WE)
	file(MAKE_DIRECTORY "${ASSETS_DIR}/material")
	set(input_path "${CMAKE_CURRENT_SOURCE_DIR}/${mat_src}")
	set(output_path "${ASSETS_DIR}/material/${filename}.filamat")
	add_custom_command(
		OUTPUT ${output_path}
		COMMAND matc -o ${output_path} ${input_path}
		COMMENT "Compiling material ${mat_src} to ${output_path}"
	)
	list(APPEND RESOURCE_BINS ${output_path})
endforeach()

add_custom_command(
	OUTPUT ${ASSETS_DIR}/resources/gl_materials.c
	COMMAND resgen -c --package=gl_materials --deploy=${ASSETS_DIR}/resources ${RESOURCE_BINS}
	DEPENDS ${RESOURCE_BINS}
	COMMENT "Aggregating resources"
)

include_directories(
	BEFORE "${ASSETS_DIR}"
)

add_library(${MODULE_NAME} STATIC
	"Material.cpp"
	"LitMaterial.cpp"
	"SubsurfaceMaterial.cpp"
	"ClothMaterial.cpp"
	"UnlitMaterial.cpp"
	"SpecularGlossinessMaterial.cpp"
	"${ASSETS_DIR}/resources/gl_materials.c"
)

target_link_libraries(${MODULE_NAME}
	filament filamat smol-v
	fwlab_assets fwlab_texture
)
