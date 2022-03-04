set(MODULE_NAME fwlab_geometry)

add_library(${MODULE_NAME} STATIC
	"PlaneGeometry.cpp"
	"BoxGeometry.cpp"
)

target_link_libraries(${MODULE_NAME}
	filament
	fwlab_core
)
