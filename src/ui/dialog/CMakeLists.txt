set(MODULE_NAME fwlab_ui_dialog)

add_library(${MODULE_NAME} STATIC
	"OpenFileDialog.cpp"
	"SaveFileDialog.cpp"
)

target_link_libraries(${MODULE_NAME}
	filament filagui utils
)
