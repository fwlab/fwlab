set(MODULE_NAME fwlab_scene)

# 使用BEFORE避免引入其他目录下的resources/resources.h
include_directories(
	BEFORE "${CMAKE_BINARY_DIR}/assets"
)

add_library(${MODULE_NAME} STATIC
	"Scene.cpp"
 )

target_link_libraries(${MODULE_NAME}
	filament filamentapp
	fwlab_camera fwlab_object fwlab_material fwlab_light fwlab_loader
)
