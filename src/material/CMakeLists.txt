set(MODULE_NAME fwlab_material)

include_directories(
	BEFORE "${CMAKE_BINARY_DIR}/assets"
)

add_library(${MODULE_NAME} STATIC
	"Material.cpp"
	"LitMaterial.cpp"
	"SubsurfaceMaterial.cpp"
	"ClothMaterial.cpp"
	"UnlitMaterial.cpp"
	"SpecularGlossinessMaterial.cpp"
)

target_link_libraries(${MODULE_NAME}
	filament filamat smol-v
	fwlab_assets fwlab_texture
)
