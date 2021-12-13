set(MODULE_NAME fwlab_scene_object)

add_library(${MODULE_NAME} STATIC
	triangle.cpp
)

target_link_libraries(${MODULE_NAME}
	filament filamentapp
)
