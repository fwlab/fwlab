set(MODULE_NAME fwlab_gl_renderer)

add_library(${MODULE_NAME} STATIC
	"OpenGLRenderer.cpp"
)

target_link_libraries(${MODULE_NAME}
	filament filamentapp
	fwlab_gl_scene fwlab_gl_camera
)
