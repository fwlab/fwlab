set(MODULE_NAME fwlab_assets)

set(ASSETS_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(RESOURCE_BINS)

# 资源文件
set(MATERIAL_SRCS
	"materials/defaultMaterial.mat"
	"materials/aiDefaultMat.mat"
	"materials/standard_material.mat"
	"materials/textured.mat"
	"materials/bakedColor.mat"
)
set(MAP_SRCS
	"environments/lightroom_14b.hdr"
)

# 处理材质
foreach (mat_src ${MATERIAL_SRCS})
	get_filename_component(filename "${mat_src}" NAME_WE)
	set(input_path "${CMAKE_CURRENT_SOURCE_DIR}/${mat_src}")
	set(output_path "${ASSETS_DIR}/material/${filename}.filamat")
	add_custom_command(
		OUTPUT ${output_path}
		COMMAND matc -o ${output_path} ${input_path}
	)
	list(APPEND RESOURCE_BINS ${output_path})
endforeach()

# 处理环境贴图
set(CMGEN_ARGS --format=ktx --size=256 --extract-blur=0.1)

foreach(env_src ${MAP_SRCS})
	get_filename_component(filename "${env_src}" NAME_WE)
	set(source_envmap "${CMAKE_CURRENT_SOURCE_DIR}/${env_src}")

    set(target_skybox "${ASSETS_DIR}/ibl/${filename}/${filename}_skybox.ktx")
    set(target_envmap "${ASSETS_DIR}/ibl/${filename}/${filename}_ibl.ktx")

    add_custom_command(
		OUTPUT ${target_skybox} ${target_envmap}
        COMMAND cmgen -x ${ASSETS_DIR}/ibl/${filename} ${CMGEN_ARGS} ${source_envmap}
    )

	list(APPEND RESOURCE_BINS ${target_skybox} ${target_envmap})
endforeach()

# 处理OBJ模型
set(OBJ_PATH
	"models/monkey/monkey.obj"
)
get_filename_component(meshname "${OBJ_PATH}" NAME_WE)
set(source_mesh "${CMAKE_CURRENT_SOURCE_DIR}/${OBJ_PATH}")
set(target_mesh "${ASSETS_DIR}/models/${meshname}/${meshname}.filamesh")
    add_custom_command(
		OUTPUT ${target_mesh}
        COMMAND filamesh --compress ${source_mesh} ${target_mesh}
)
list(APPEND RESOURCE_BINS ${target_mesh})

# 处理模型贴图
set(TEXTURE_SRCS
	"models/monkey/albedo.png"
	"models/monkey/roughness.png"
	"models/monkey/metallic.png"
	"models/monkey/ao.png"
)

set (COMPRESSION "--compression=s3tc_rgba_dxt5")
foreach(tex_src ${TEXTURE_SRCS})
	get_filename_component(filename "${tex_src}" NAME_WE)
	set(EXTRA_ARGS)
	if (NOT ${filaname} STREQUAL "albedo")
		set(EXTRA_ARGS ";--grayscale")
	endif()
	set(source_path "${CMAKE_CURRENT_SOURCE_DIR}/${tex_src}")
    set(target_path "${ASSETS_DIR}/models/${meshname}/${filename}.ktx")
    add_custom_command(
        OUTPUT ${target_path}
        COMMAND mipgen --quiet ${source_path} ${target_path} ${COMPRESSION}${EXTRA_ARGS}
	)
	list(APPEND RESOURCE_BINS ${target_path})
endforeach()

# 复制法线贴图
set(NORMAL_SRC "models/monkey/normal.png")
get_filename_component(filename "${NORMAL_SRC}" NAME_WE)
set(source_path "${CMAKE_CURRENT_SOURCE_DIR}/${NORMAL_SRC}")
set(target_path "${ASSETS_DIR}/models/${meshname}/${filename}.png")
add_custom_command(
	OUTPUT ${target_path}
	COMMAND ${CMAKE_COMMAND} -E copy ${source_path} ${target_path}
)
list(APPEND RESOURCE_BINS ${target_path})

# 复制字体文件
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/fonts/Roboto-License.txt" DESTINATION "${ASSETS_DIR}/fonts")
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/fonts/Roboto-Medium.ttf" DESTINATION "${ASSETS_DIR}/fonts")

# 复制模型
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/models/RobotDog/scene.gltf" DESTINATION "${ASSETS_DIR}/models/RobotDog")
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/models/RobotDog/scene.bin" DESTINATION "${ASSETS_DIR}/models/RobotDog")
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/models/RobotDog/textures/spot_baseColor.png" DESTINATION "${ASSETS_DIR}/models/RobotDog/textures")
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/models/RobotDog/textures/spot_emissive.jpeg" DESTINATION "${ASSETS_DIR}/models/RobotDog/textures")
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/models/RobotDog/textures/spot_metallicRoughness.png" DESTINATION "${ASSETS_DIR}/models/RobotDog/textures")
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/models/RobotDog/textures/spot_normal.png" DESTINATION "${ASSETS_DIR}/models/RobotDog/textures")

# 打包资源
add_custom_command(
	OUTPUT ${ASSETS_DIR}/resources/resources.c
	COMMAND resgen -c --deploy=${ASSETS_DIR}/resources ${RESOURCE_BINS}
	DEPENDS ${RESOURCE_BINS}
)

add_library(${MODULE_NAME} STATIC
	"${ASSETS_DIR}/resources/resources.c"
	"${font_target_path}"
)
