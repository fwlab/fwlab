set(MODULE_NAME fwlab_light)

add_library(${MODULE_NAME} STATIC
	"Light.cpp"
)

target_link_libraries(${MODULE_NAME}
	filament filamentapp
)
