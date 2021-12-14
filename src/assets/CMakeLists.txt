set(MODULE_NAME fwlab_assets)

set(ASSETS_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(RESOURCE_BINS)

# 资源文件
set(MATERIAL_SRCS
	"materials/defaultMaterial.mat"
)
set(TEXTURE_SRCS
	"textures/ibl_river_roughness_m0.png"
)

# 处理材质
foreach (mat_src ${MATERIAL_SRCS})
	get_filename_component(localname "${mat_src}" NAME_WE)
	set(input_path "${CMAKE_CURRENT_SOURCE_DIR}/${mat_src}")
	set(output_path "${ASSETS_DIR}/material/${localname}.filamat")
	add_custom_command(
		OUTPUT ${output_path}
		COMMAND matc -o ${output_path} ${input_path}
	)
	list(APPEND RESOURCE_BINS ${output_path})
endforeach()

# 处理贴图


# 打包资源
add_custom_command(
	OUTPUT ${ASSETS_DIR}/resources/resources.c
	COMMAND resgen -c --deploy=${ASSETS_DIR}/resources ${RESOURCE_BINS}
	DEPENDS ${RESOURCE_BINS}
)

add_library(${MODULE_NAME} STATIC
	"${CMAKE_CURRENT_SOURCE_DIR}/dummy.c"
	"${ASSETS_DIR}/resources/resources.c"
)
