set(MODULE_NAME fwlab_gl_light)

add_library(${MODULE_NAME} STATIC
	"Light.cpp"
	"SunLight.h"
	"DirectionalLight.h"
	"PointLight.h"
	"FocusedSpotLight.h"
	"SpotLight.h"
)

target_link_libraries(${MODULE_NAME}
	filament filamentapp
	fwlab_gl_core
)
