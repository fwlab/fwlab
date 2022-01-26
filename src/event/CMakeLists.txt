set(MODULE_NAME fwlab_event)

add_library(${MODULE_NAME} STATIC
	"BaseEvent.cpp"
	"EventDispatcher.cpp"
)

target_link_libraries(${MODULE_NAME}
	filament sdl2
)
