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
foreach(tex_src ${TEXTURE_SRCS})
	get_filename_component(localname "${tex_src}" NAME_WE)
	set(input_path "${CMAKE_CURRENT_SOURCE_DIR}/${tex_src}")
	set(output_path "${ASSETS_DIR}/textures")
	add_custom_command(
		OUTPUT ${output_path}
		COMMAND cmgen ${input_path} -x ${output_path}
	)
	# list(APPEND RESOURCE_BINS ${output_path})
endforeach()

function(add_envmap SOURCE TARGET)
    set(source_envmap "${ROOT_DIR}/${SOURCE}")

    set(target_skybox "${PROJECT_BINARY_DIR}/assets/ibl/${TARGET}/${TARGET}_skybox.ktx")
    set(target_envmap "${PROJECT_BINARY_DIR}/assets/ibl/${TARGET}/${TARGET}_ibl.ktx")

    set(target_envmaps ${target_envmaps} ${target_skybox} PARENT_SCOPE)
    set(target_envmaps ${target_envmaps} ${target_envmap} PARENT_SCOPE)

    add_custom_command(OUTPUT ${target_skybox} ${target_envmap}
        COMMAND cmgen -x assets/ibl/${TARGET} ${CMGEN_ARGS} ${source_envmap}
        MAIN_DEPENDENCY ${source_envmap}
        DEPENDS cmgen
        COMMENT "Generating environment map ${target_envmap}")
endfunction()

# 打包资源
add_custom_command(
	OUTPUT ${ASSETS_DIR}/resources/resources.c
	COMMAND resgen -c --deploy=${ASSETS_DIR}/resources ${RESOURCE_BINS}
	DEPENDS ${RESOURCE_BINS}
)

add_library(${MODULE_NAME} STATIC
	"${ASSETS_DIR}/resources/resources.c"
)
