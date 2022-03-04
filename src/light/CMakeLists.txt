set(MODULE_NAME fwlab_light)

add_library(${MODULE_NAME} STATIC
	"Light.cpp"
	"AmbientLight.cpp"
	"SunLight.cpp"
	"DirectionalLight.cpp"
	"PointLight.cpp"
	"FocusedSpotLight.cpp"
	"SpotLight.cpp"
)

target_link_libraries(${MODULE_NAME}
	filament
	fwlab_core fwlab_loader
)
