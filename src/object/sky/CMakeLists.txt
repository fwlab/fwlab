set(MODULE_NAME fwlab_object_sky)

add_library(${MODULE_NAME} STATIC
	"SkyBox.cpp"
)

target_link_libraries(${MODULE_NAME}
	filament math
)
