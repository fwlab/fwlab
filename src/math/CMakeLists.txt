set(MODULE_NAME fwlab_math)

add_library(${MODULE_NAME} STATIC
	"mat4.cpp"
)

target_link_libraries(${MODULE_NAME}
	filament math
)
