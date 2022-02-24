set(MODULE_NAME fwlab_ui_framerate)

add_library(${MODULE_NAME} STATIC
	"Framerate.cpp"
)

target_link_libraries(${MODULE_NAME}
	filament filagui utils
	fwlab_context fwlab_utils fwlab_event
)
