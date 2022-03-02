set(MODULE_NAME fwlab_ui_sidebar)

add_subdirectory(scene)
add_subdirectory(property)

add_library(${MODULE_NAME} STATIC
	"SideBar.cpp"
)

target_link_libraries(${MODULE_NAME}
	filament filagui utils
	fwlab_context fwlab_utils fwlab_event
	fwlab_ui_sidebar_scene fwlab_ui_sidebar_property
)
