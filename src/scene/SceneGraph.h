#ifndef FWLAB_SCENE_SCENE_GRAPH_H
#define FWLAB_SCENE_SCENE_GRAPH_H
#include <stdint.h>
#include <filament/IndirectLight.h>
#include <filament/Scene.h>
#include <filament/Skybox.h>
#include <utils/Entity.h>
#include "../core/Object3D.h"

namespace fwlab::scene
{
	class SceneGraph : public core::Object3D
	{
	public:
		SceneGraph(filament::Scene* scene);
		virtual ~SceneGraph();
		bool add(Object3D* child) override;
		bool remove(Object3D* child) override;
		filament::Scene* getScene() const;
		void setScene(filament::Scene* scene);

		// scene
		filament::Skybox* getSkybox() const;
		void setSkybox(filament::Skybox* skybox);
		void setIndirectLight(filament::IndirectLight* ibl);
		void addEntities(const ::utils::Entity* entities, size_t count);

	private:
		filament::Scene* scene = nullptr;
	};
}

#endif