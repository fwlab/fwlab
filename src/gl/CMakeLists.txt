set(MODULE_NAME fwlab_gl)

add_subdirectory(utils)
add_subdirectory(core)
add_subdirectory(geometry)
add_subdirectory(material)
add_subdirectory(object)
add_subdirectory(camera)
add_subdirectory(light)
add_subdirectory(loader)

add_library(${MODULE_NAME} STATIC "gl.cpp")

target_link_libraries(${MODULE_NAME}
	filament filamentapp
	fwlab_gl_core fwlab_gl_geometry fwlab_gl_material 
	fwlab_gl_object fwlab_gl_camera fwlab_gl_light fwlab_gl_loader
)
