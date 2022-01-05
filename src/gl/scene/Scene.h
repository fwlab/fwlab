#ifndef GL_SCENE_SCENE_H
#define GL_SCENE_SCENE_H
#include <filament/Engine.h>
#include <filament/View.h>
#include <filament/Scene.h>
#include <filament/Renderer.h>
#include "../core/Object3D.h"

namespace gl::scene
{
	class Scene : gl::core::Object3D {
	public:
		Scene();
		virtual ~Scene();
	};
}

#endif