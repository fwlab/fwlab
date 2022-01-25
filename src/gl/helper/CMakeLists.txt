set(MODULE_NAME fwlab_gl_helper)

add_library(${MODULE_NAME} STATIC
	"GridHelper.cpp"
	"ArrowHelper.h"
	"ArrowHelper.cpp"
	"AxesHelper.cpp"
)

target_link_libraries(${MODULE_NAME}
	filament
	fwlab_gl_core fwlab_gl_utils
)
