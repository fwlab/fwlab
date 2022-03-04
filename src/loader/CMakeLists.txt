set(MODULE_NAME fwlab_loader)

add_library(${MODULE_NAME} STATIC
	"IBL.cpp"
	"FilameshLoader.cpp"
	"GltfLoader.cpp"
	"ImageLoader.cpp"
	"TextureLoader.cpp"
)

target_link_libraries(${MODULE_NAME}
	filament filameshio gltfio gltfio_core gltfio_resources gltfio_resources_lite
	fwlab_utils fwlab_core fwlab_texture fwlab_material
)
