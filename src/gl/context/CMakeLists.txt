set(MODULE_NAME fwlab_gl_context)

add_library(${MODULE_NAME} STATIC
	"context.cpp"
)

target_link_libraries(${MODULE_NAME}
	filament filamentapp
)
