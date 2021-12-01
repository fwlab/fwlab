set(MODULE_NAME fwlab)

add_executable(${MODULE_NAME} WIN32
    main.cpp
)

target_link_libraries(${MODULE_NAME}
	filament filamentapp sample-resources
)
