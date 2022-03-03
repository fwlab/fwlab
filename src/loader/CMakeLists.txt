set(MODULE_NAME fwlab_gl_loader)

add_library(${MODULE_NAME} STATIC
	"Loader.h"
	"MeshLoader.cpp"
	"FilameshLoader.cpp"
	"ImageLoader.cpp"
	"TextureLoader.cpp"
 )

target_link_libraries(${MODULE_NAME}
	filament
	fwlab_gl_utils fwlab_gl_core fwlab_gl_texture fwlab_gl_material
)
