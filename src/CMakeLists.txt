set(MODULE_NAME fwlab)

add_subdirectory(utils)
add_subdirectory(camera)
add_subdirectory(object)
add_subdirectory(scene)

add_executable(${MODULE_NAME} WIN32
    main.cpp application.cpp
)

target_link_libraries(${MODULE_NAME}
	filament filamentapp sample-resources
	fwlab_scene fwlab_utils
)
