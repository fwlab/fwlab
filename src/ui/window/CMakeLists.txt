set(MODULE_NAME fwlab_ui_window)

add_library(${MODULE_NAME} STATIC
	"Message.cpp"
	"Confirm.cpp"
	"Prompt.cpp"
)

target_link_libraries(${MODULE_NAME}
	filament filagui utils
)
