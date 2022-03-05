set(MODULE_NAME fwlab_ui)

include_directories(
	BEFORE "${CMAKE_CURRENT_BINARY_DIR}/../material/generated"
)

add_library(${MODULE_NAME} STATIC
	"ImGuiHelper.cpp"
	"UIHelper.cpp"
	"Component.cpp"
)

target_link_libraries(${MODULE_NAME}
	filament filagui utils
	fwlab_context fwlab_utils fwlab_material fwlab_event
)
