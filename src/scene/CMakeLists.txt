set(MODULE_NAME fwlab_scene)

# 使用BEFORE避免引入其他目录下的resources/resources.h
include_directories(
	BEFORE "${CMAKE_BINARY_DIR}/assets"
)

add_library(${MODULE_NAME} STATIC
	"Scene.cpp"
)

target_link_libraries(${MODULE_NAME}
	filament viewer gltfio gltfio_core smol-v SPIRVd
	fwlab_geometry fwlab_object_sky
)
