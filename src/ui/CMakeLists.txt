set(MODULE_NAME fwlab_ui)

include_directories(
	BEFORE "${CMAKE_CURRENT_BINARY_DIR}/../material/generated"
)

add_library(${MODULE_NAME} STATIC
	"ImGuiHelper.cpp"
	"UIHelper.cpp"
	"Component.cpp"
 "window/Message.h" "window/Message.cpp" "window/Confirm.h" "window/Confirm.cpp" "window/Prompt.h" "window/Prompt.cpp")

target_link_libraries(${MODULE_NAME}
	filament filagui utils
	fwlab_context fwlab_utils fwlab_material fwlab_event
)
