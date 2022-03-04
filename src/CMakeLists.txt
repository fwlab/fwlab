set(MODULE_NAME fwlab)

add_subdirectory(utils)
add_subdirectory(context)
add_subdirectory(math)
add_subdirectory(core)
add_subdirectory(geometry)
add_subdirectory(texture)
add_subdirectory(material)
add_subdirectory(loader)
add_subdirectory(light)
add_subdirectory(event)
add_subdirectory(event/core)
add_subdirectory(ui)
add_subdirectory(ui/menubar)
add_subdirectory(ui/sidebar)
add_subdirectory(ui/framerate)
add_subdirectory(controller)
add_subdirectory(object)
add_subdirectory(helper)
add_subdirectory(scene)

if (WIN32)
	add_executable(${MODULE_NAME} WIN32
		"main.cpp"
		"Application.cpp"
		"EventDispatcher.cpp"
		"Editor.cpp"
	)
else()
	add_executable(${MODULE_NAME}
		"main.cpp"
		"Application.cpp"
		"EventDispatcher.cpp"
		"Editor.cpp"
	)
endif()

set_target_properties(${MODULE_NAME} PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

target_link_libraries(${MODULE_NAME}
	filament sdl2 camutils
	fwlab_assets fwlab_context fwlab_event fwlab_event_core
	fwlab_ui fwlab_ui_menubar fwlab_ui_sidebar
	fwlab_scene fwlab_controller fwlab_utils
)
