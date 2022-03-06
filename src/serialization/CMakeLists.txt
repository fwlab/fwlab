set(MODULE_NAME fwlab_serialization)

add_library(${MODULE_NAME} STATIC
	"BaseSerializer.cpp"
	"Convert.cpp"
)

target_link_libraries(${MODULE_NAME}
	filament
)
