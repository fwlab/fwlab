set(MODULE_NAME fwlab_controller)

add_library(${MODULE_NAME} STATIC
    "OrbitController.cpp"
)

target_link_libraries(${MODULE_NAME}
	filament camutils
    fwlab_context
)
