set(MODULE_NAME fwlab_loader)

add_library(${MODULE_NAME} STATIC
	"Loader.cpp"
	"FilameshLoader.cpp"
 )

target_link_libraries(${MODULE_NAME}
	filament filamentapp
)
