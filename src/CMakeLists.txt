set(MODULE_NAME fwlab)

add_subdirectory(assets)
add_subdirectory(utils)
add_subdirectory(camera)
add_subdirectory(object)
add_subdirectory(scene)

link_libraries(
	fwlab_assets
)

add_executable(${MODULE_NAME} WIN32
    "main.cpp"
	"Application.cpp"
)

set_target_properties(${MODULE_NAME} PROPERTIES
	OUTPUT_PATH ${CMAKE_BINARY_DIR}
)

target_link_libraries(${MODULE_NAME}
	filament filamentapp
	fwlab_assets fwlab_scene fwlab_utils
)
