cmake_minimum_required(VERSION 3.19)

project(filamentapp C ASM)

set(MODULE_NAME fwlab_ui)

add_library(${MODULE_NAME} STATIC
	"UIHelper.cpp"
)

target_link_libraries(${MODULE_NAME}
	filament filagui
	utils fwlab_context fwlab_event
)
