set(MODULE_NAME fwlab_ui_menubar)

add_library(${MODULE_NAME} STATIC
	"MenuBar.cpp"
	"FileMenu.cpp"
	"EditMenu.cpp"
	"ObjectMenu.cpp"
	"LightMenu.cpp"
	"TrainMenu.cpp"
	"ExperimentMenu.cpp"
	"OptionsMenu.cpp"
	"HelpMenu.cpp"
)

target_link_libraries(${MODULE_NAME}
	filament filagui utils
	fwlab_context fwlab_utils fwlab_event fwlab_ui_dialog
)
