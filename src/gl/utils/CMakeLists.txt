set(MODULE_NAME fwlab_gl_utils)

add_library(${MODULE_NAME} STATIC
	"Logger.cpp"
	"TimeUtils.cpp"
	"ImageUtils.cpp"
	"Utils.cpp"
)

target_link_libraries(${MODULE_NAME}
	filament filamentapp
)