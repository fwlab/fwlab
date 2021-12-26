set(MODULE_NAME fwlab_gl_scene)

add_library(${MODULE_NAME} STATIC
	"Scene.cpp"
)

target_link_libraries(${MODULE_NAME}
	filament filamentapp
	fwlab_gl_core
)
