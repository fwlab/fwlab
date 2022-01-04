set(MODULE_NAME fwlab_scene)

# 使用BEFORE避免引入其他目录下的resources/resources.h
include_directories(
	BEFORE "${CMAKE_BINARY_DIR}/assets"
)

add_library(${MODULE_NAME} STATIC
	"Scene.cpp"
	"BoxScene.cpp"
	"SuzanneScene.cpp"
	"RobotDogScene.cpp"
  "ImGuiScene.h" "ImGuiScene.cpp" "AnimationScene.cpp" "AnimationScene.h")

target_link_libraries(${MODULE_NAME}
	filament filamentapp viewer gltfio gltfio_core
	fwlab_gl
)
