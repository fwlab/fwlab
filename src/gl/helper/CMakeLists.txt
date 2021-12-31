set(MODULE_NAME fwlab_gl_helper)

add_library(${MODULE_NAME} STATIC
	"GridHelper.cpp"
 "ArrowHelper.h" "ArrowHelper.cpp" "AxesHelper.h" "AxesHelper.cpp")

target_link_libraries(${MODULE_NAME}
	filament filamentapp
	fwlab_gl_core fwlab_gl_utils
)
