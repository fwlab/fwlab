set(MODULE_NAME fwlab_gl_light)

add_library(${MODULE_NAME} STATIC
	"Light.cpp"
	"SunLight.cpp"
	"DirectionalLight.cpp"
	"PointLight.cpp"
	"FocusedSpotLight.cpp"
	"SpotLight.cpp"
)

target_link_libraries(${MODULE_NAME}
	filament filamentapp
	fwlab_gl_core
)
