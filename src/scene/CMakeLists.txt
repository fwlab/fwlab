set(MODULE_NAME fwlab_scene)

add_library(${MODULE_NAME} STATIC
	scene.cpp
)

target_link_libraries(${MODULE_NAME}
	filament filamentapp sample-resources
)
