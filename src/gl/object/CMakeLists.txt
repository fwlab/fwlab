set(MODULE_NAME fwlab_gl_object)

add_library(${MODULE_NAME} STATIC
    "Object3D.cpp"
	"Mesh.cpp"
	"Skybox.cpp"
 )

target_link_libraries(${MODULE_NAME}
	filament filamentapp
	fwlab_gl_core fwlab_gl_geometry
)
