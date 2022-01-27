set(MODULE_NAME fwlab_editor)

add_library(${MODULE_NAME} STATIC
	"Editor.cpp"
)

target_link_libraries(${MODULE_NAME}
	filament
)
