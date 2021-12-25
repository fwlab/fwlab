set(MODULE_NAME fwlab_gl_camera)

add_library(${MODULE_NAME} STATIC
	"PerspectiveCamera.cpp"
	"OrthographicCamera.cpp"
)

target_link_libraries(${MODULE_NAME}
	filament filamentapp
)
