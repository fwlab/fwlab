set(MODULE_NAME fwlab_scene)

add_subdirectory(assets)

include_directories(
	${CMAKE_CURRENT_BINARY_DIR}/assets
)

add_library(${MODULE_NAME} STATIC
	"Scene.cpp"
 )

target_link_libraries(${MODULE_NAME}
	filament filamentapp sample-resources gltfio_core viewer
	fwlab_camera fwlab_object fwlab_scene_assets
)
