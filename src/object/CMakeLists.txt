set(MODULE_NAME fwlab_object)

add_library(${MODULE_NAME} STATIC
	"Skybox.cpp"
	"Mesh.cpp"
)

target_link_libraries(${MODULE_NAME}
	filament math
	fwlab_geometry fwlab_material
)
