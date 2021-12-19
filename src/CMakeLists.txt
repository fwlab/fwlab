set(MODULE_NAME fwlab)

add_subdirectory(utils)
add_subdirectory(camera)
add_subdirectory(geometry)
add_subdirectory(material)
add_subdirectory(object)
add_subdirectory(light)
add_subdirectory(loader)
add_subdirectory(scene)

# 生成图标文件
set(APP_ICON_RESOURCE_WINDOWS "${CMAKE_BINARY_DIR}/assets/app.rc")
set(APP_ICON_DATA "APP_ICON ICON DISCARDABLE \"${CMAKE_SOURCE_DIR}/assets/icons/miku.ico\"")
string(REPLACE "/" "\\\\" APP_ICON_DATA ${APP_ICON_DATA})
add_custom_command(
	OUTPUT ${APP_ICON_RESOURCE_WINDOWS}
	COMMAND echo ${APP_ICON_DATA} > ${APP_ICON_RESOURCE_WINDOWS}
)

add_executable(${MODULE_NAME} WIN32
    "main.cpp"
	"Application.cpp"
	${APP_ICON_RESOURCE_WINDOWS}
)

set_target_properties(${MODULE_NAME} PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

target_link_libraries(${MODULE_NAME}
	filament filamentapp
	fwlab_assets fwlab_scene fwlab_utils
)
