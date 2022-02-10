set(MODULE_NAME fwlab_event_core)

add_library(${MODULE_NAME} STATIC
	"ResizeEvent.cpp"
)

target_link_libraries(${MODULE_NAME}
	filament sdl2
	fwlab_event
)
