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
	filament filamentapp shaders SPIRV-Tools SPIRV-Tools-link SPIRV-Tools-lint SPIRV-Tools-opt SPIRV-Tools-reduce
	fwlab_assets fwlab_scene fwlab_utils
)
