set(MODULE_NAME fwlab_gl_loader)

add_library(${MODULE_NAME} STATIC
	"Loader.h"
	"MeshLoader.cpp"
	"FilameshLoader.cpp"
  )

target_link_libraries(${MODULE_NAME}
	filament filamentapp
	fwlab_gl_core
)
