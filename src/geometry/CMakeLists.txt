set(MODULE_NAME fwlab_geometry)

add_library(${MODULE_NAME} STATIC
	"PlaneGeometry.cpp"
 )

target_link_libraries(${MODULE_NAME}
	filament filamentapp
	fwlab_core
)
