set(MODULE_NAME fwlab_material)

# 使用BEFORE避免引入其他目录下的resources/resources.h
include_directories(
	BEFORE "${CMAKE_BINARY_DIR}/src/assets"
)

add_library(${MODULE_NAME} STATIC
	"Material.cpp"
	"MeshBasicMaterial.cpp"
	"PointsMaterial.cpp"
	"LineBasicMaterial.cpp"
)

target_link_libraries(${MODULE_NAME}
	filament filamentapp
	fwlab_assets
)
