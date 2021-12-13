set(MODULE_NAME fwlab_camera)

add_library(${MODULE_NAME} STATIC
	perspective_camera.cpp
)

target_link_libraries(${MODULE_NAME}
	filament filamentapp
)
