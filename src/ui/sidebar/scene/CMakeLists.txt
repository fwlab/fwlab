set(MODULE_NAME fwlab_ui_sidebar_scene)

add_library(${MODULE_NAME} STATIC
	"ScenePanel.cpp"
	"HirarchyPanel.cpp"
	"HistoryPanel.cpp"
)

target_link_libraries(${MODULE_NAME}
	filament filagui utils
	fwlab_context fwlab_utils fwlab_event
)
