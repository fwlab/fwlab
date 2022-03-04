set(MODULE_NAME fwlab_loader)

add_library(${MODULE_NAME} STATIC
	"Loader.h"
	"MeshLoader.cpp"
	"FilameshLoader.cpp"
	"ImageLoader.cpp"
	"TextureLoader.cpp"
 )

target_link_libraries(${MODULE_NAME}
	filament
	fwlab_utils fwlab_core fwlab_texture fwlab_material
)
