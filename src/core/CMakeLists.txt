set(MODULE_NAME fwlab_core)

add_library(${MODULE_NAME} STATIC
	"IDisposable.h"
	"BufferAttribute.cpp"
	"BufferGeometry.cpp"
	"Object3D.cpp"
)

target_link_libraries(${MODULE_NAME}
	filament
	fwlab_math fwlab_utils
)
