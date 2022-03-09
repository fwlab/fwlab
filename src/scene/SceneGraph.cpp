#include "SceneGraph.h"

namespace fwlab::scene
{
	SceneGraph::SceneGraph(filament::Scene* scene)
	{
		this->scene = scene;
	}

	SceneGraph::~SceneGraph()
	{
		if (light)
		{
			delete light;
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

	bool SceneGraph::addLight(light::AmbientLight* light)
	{
		if (this->light)
		{
			delete this->light;
		}

		this->light = light;
		scene->setSkybox(light->getSkybox());
		scene->setIndirectLight(light->getIndirectLight());
		return true;
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

	bool SceneGraph::removeLight(light::AmbientLight* light)
	{
		if (this->light)
		{
			delete this->light;
			this->light = nullptr;
		}
		scene->setSkybox(nullptr);
		scene->setIndirectLight(nullptr);
		return true;
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