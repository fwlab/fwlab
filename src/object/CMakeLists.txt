set(MODULE_NAME fwlab_object)

add_library(${MODULE_NAME} STATIC
    "Object3D.cpp"
	"Mesh.cpp"
	"Skybox.cpp"
	"Triangle.cpp"
	"Rectangle.cpp"
	"Point.cpp" 
	"Line.cpp"
 )

target_link_libraries(${MODULE_NAME}
	filament filamentapp
	fwlab_geometry
)
