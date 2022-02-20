set(MODULE_NAME fwlab_ui_sidebar_property)

add_library(${MODULE_NAME} STATIC
	"PropertyPanel.cpp"
)

target_link_libraries(${MODULE_NAME}
	filament filagui utils
	fwlab_context fwlab_utils fwlab_event
)
