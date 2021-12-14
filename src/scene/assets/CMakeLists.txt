set(MODULE_NAME fwlab_scene_assets)

set(GENERATED_DIR "${CMAKE_CURRENT_BINARY_DIR}/generated")
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
	set(output_path "${GENERATED_DIR}/material/${localname}.filamat")
	add_custom_command(
		OUTPUT ${output_path}
		COMMAND matc -o ${output_path} ${input_path}
	)
	list(APPEND RESOURCE_BINS ${output_path})
endforeach()

# 处理贴图
foreach (texture_src ${TEXTURE_SRCS})
	get_filename_component(localname "${texture_src}" NAME_WE)
	set(input_path "${CMAKE_CURRENT_SOURCE_DIR}/${texture_src}")
	set(output_path "${GENERATED_DIR}/texture")
	add_custom_command(
		OUTPUT ${output_path}
		COMMAND cmgen -x ${output_path} ${input_path}
	)
	# list(APPEND RESOURCE_BINS ${output_path})
endforeach()

# 打包资源
add_custom_command(
	OUTPUT ${GENERATED_DIR}/resources/resources.c
	COMMAND resgen -c --deploy=${GENERATED_DIR}/resources ${RESOURCE_BINS}
	DEPENDS ${RESOURCE_BINS}
)

set(DUMMY_SRC "${GENERATED_DIR}/resources/dummy.c")
add_custom_command(OUTPUT ${DUMMY_SRC} COMMAND echo "//" > ${DUMMY_SRC})

add_library(${MODULE_NAME} STATIC
	"${DUMMY_SRC}"
	"${GENERATED_DIR}/resources/resources.c"
)
