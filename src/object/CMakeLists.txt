set(MODULE_NAME fwlab_object)

add_library(${MODULE_NAME} STATIC
	"Skybox.cpp"
	"Triangle.cpp"
	"Rectangle.cpp"
	"Point.cpp")

target_link_libraries(${MODULE_NAME}
	filament filamentapp
)
