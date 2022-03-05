set(MODULE_NAME fwlab_assets)

set(ASSETS_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(RESOURCE_BINS)

# 处理材质
set(MATERIAL_SRCS
	"materials/uiBlit.mat"
	"materials/lit.mat"
	"materials/subsurface.mat"
	"materials/cloth.mat"
	"materials/unlit.mat"
	"materials/specular_glossiness.mat"
)

foreach (mat_src ${MATERIAL_SRCS})
	get_filename_component(filename "${mat_src}" NAME_WE)
	file(MAKE_DIRECTORY "${ASSETS_DIR}/material")
	set(input_path "${CMAKE_CURRENT_SOURCE_DIR}/${mat_src}")
	set(output_path "${ASSETS_DIR}/material/${filename}.filamat")
	add_custom_command(
		OUTPUT ${output_path}
		COMMAND matc -a opengl -p desktop -gd -o ${output_path} ${input_path}
	)
	list(APPEND RESOURCE_BINS ${output_path})
endforeach()

# 处理环境贴图
set(MAP_SRCS
	"environments/lightroom_14b.hdr"
)

set(CMGEN_ARGS --quiet --format=ktx --size=256 --extract-blur=0.1)

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

# 复制字体文件
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/fonts/Roboto-Medium.ttf" DESTINATION "${ASSETS_DIR}/fonts")
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/fonts/Roboto-License.txt" DESTINATION "${ASSETS_DIR}/fonts")
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/fonts/Alibaba-PuHuiTi-Bold.ttf" DESTINATION "${ASSETS_DIR}/fonts")
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/fonts/Law Policy for Alibaba Sans.pdf" DESTINATION "${ASSETS_DIR}/fonts")
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/fonts/法务版权声明.pdf" DESTINATION "${ASSETS_DIR}/fonts")

# 复制图片
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/images/girl.jpg" DESTINATION "${ASSETS_DIR}/images")
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/images/girl.png" DESTINATION "${ASSETS_DIR}/images")

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

# 安装
set(INSTALL_FILES
	"/fonts/"
	"/ibl/"
	"/images/"
	"/models/"
)

foreach(file ${INSTALL_FILES})
	if ("${file}" MATCHES "/$")
		install(DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}${file}" DESTINATION "${CMAKE_INSTALL_PREFIX}/assets${file}")
	else()
		install(FILES "${CMAKE_CURRENT_BINARY_DIR}${file}" DESTINATION "${CMAKE_INSTALL_PREFIX}/assets${file}")
	endif()
endforeach()