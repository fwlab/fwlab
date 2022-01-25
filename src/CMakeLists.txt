set(MODULE_NAME fwlab)

add_subdirectory(utils)
add_subdirectory(gl)
add_subdirectory(event)
add_subdirectory(scene)

add_executable(${MODULE_NAME}
    "main.cpp"
	"Application.cpp"
)

set_target_properties(${MODULE_NAME} PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

target_link_libraries(${MODULE_NAME}
	filament shaders smol-v filagui camutils
	fwlab_assets fwlab_scene fwlab_utils
)
