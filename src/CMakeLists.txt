set(MODULE_NAME fwlab)

add_subdirectory(utils)
add_subdirectory(context)
add_subdirectory(gl)
add_subdirectory(event)
add_subdirectory(event/core)
add_subdirectory(ui)
add_subdirectory(ui/menubar)
add_subdirectory(controller)
add_subdirectory(object)
add_subdirectory(scene)

add_executable(${MODULE_NAME}
    "main.cpp"
	"Application.cpp"
	"EventDispatcher.cpp"
	"Editor.cpp"
)

set_target_properties(${MODULE_NAME} PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

target_link_libraries(${MODULE_NAME}
	filament sdl2 camutils
	fwlab_assets fwlab_context fwlab_event fwlab_event_core
	fwlab_ui fwlab_ui_menubar fwlab_scene fwlab_controller fwlab_utils
)
