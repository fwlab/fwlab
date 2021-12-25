set(MODULE_NAME fwlab_core)

add_library(${MODULE_NAME} STATIC
	"BufferAttribute.cpp"
	"BufferGeometry.cpp"
)

target_link_libraries(${MODULE_NAME}
	filament filamentapp
)
