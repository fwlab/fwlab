set(MODULE_NAME fwlab_texture)

add_library(${MODULE_NAME} STATIC
	"Texture.cpp"
)

target_link_libraries(${MODULE_NAME}
	filament
	fwlab_core
)
