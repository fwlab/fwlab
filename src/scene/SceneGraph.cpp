#include "SceneGraph.h"

namespace fwlab::scene
{
	SceneGraph::SceneGraph(filament::Scene* scene)
	{
		this->scene = scene;
		this->name = "场景";
	}

	SceneGraph::~SceneGraph()
	{
		if (ambientLight)
		{
			delete ambientLight;
		}
	}

	bool SceneGraph::add(Object3D* child)
	{
		if (core::Object3D::add(child))
		{
			scene->addEntity(child->getEntity());
			return true;
		}
		return false;
	}

	bool SceneGraph::remove(Object3D* child)
	{
		if (core::Object3D::remove(child))
		{
			scene->remove(child->getEntity());
			return true;
		}
		return false;
	}

	bool SceneGraph::addAmbientLight(light::AmbientLight* light)
	{
		if (ambientLight)
		{
			delete ambientLight;
		}

		ambientLight = light;
		scene->setSkybox(light->getSkybox());
		scene->setIndirectLight(light->getIndirectLight());
		return true;
	}

	bool SceneGraph::removeAmbientLight()
	{
		if (ambientLight)
		{
			delete ambientLight;
			ambientLight = nullptr;
		}
		scene->setSkybox(nullptr);
		scene->setIndirectLight(nullptr);
		return true;
	}

	light::AmbientLight* SceneGraph::getAmbientLight() const
	{
		return ambientLight;
	}

	filament::Scene* SceneGraph::getScene() const
	{
		return scene;
	}

	void SceneGraph::setScene(filament::Scene* scene)
	{
		this->scene = scene;
	}

	filament::Skybox* SceneGraph::getSkybox() const
	{
		return scene->getSkybox();
	}

	void SceneGraph::setSkybox(filament::Skybox* skybox)
	{
		scene->setSkybox(skybox);
	}

	void SceneGraph::setIndirectLight(filament::IndirectLight* ibl)
	{
		scene->setIndirectLight(ibl);
	}

	void SceneGraph::addEntities(const ::utils::Entity* entities, size_t count)
	{
		scene->addEntities(entities, count);
	}
}