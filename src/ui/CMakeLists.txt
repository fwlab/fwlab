set(MODULE_NAME fwlab_ui)

add_library(${MODULE_NAME} STATIC
	"ImGuiHelper.cpp"
	"UIHelper.cpp"
	"Component.cpp"
)

target_link_libraries(${MODULE_NAME}
	filament filagui utils
	fwlab_context fwlab_assets fwlab_utils fwlab_event
)
