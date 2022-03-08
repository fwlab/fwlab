#ifndef FWLAB_SCENE_SCENE_GRAPH_H
#define FWLAB_SCENE_SCENE_GRAPH_H
#include <filament/Scene.h>
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

	private:
		filament::Scene* scene = nullptr;
	};
}

#endif