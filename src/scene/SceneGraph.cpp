#include <filament/TransformManager.h>
#include "SceneGraph.h"
#include "../context/context.h"

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

	bool SceneGraph::addFilamentAsset(gltfio::FilamentAsset* asset)
	{
		auto entity = asset->getRoot();
		if (!addFilamentAssetNode(&entity, this))
		{
			return false;
		}
		return true;
	}

	bool SceneGraph::addFilamentAssetNode(::utils::Entity* entity, core::Object3D* parent)
	{
		auto& manager = app->getEngine()->getTransformManager();
		auto instance = manager.getInstance(*entity);

		auto obj = new core::Object3D();
		obj->setName(std::to_string(entity->getId()));
		obj->setEntity(*entity);
		auto matrix = manager.getTransformAccurate(instance);
		obj->setMatrix(matrix);
		parent->add(obj);

		auto count = manager.getChildCount(instance);
		::utils::Entity* entities = new ::utils::Entity[count];
		manager.getChildren(instance, entities, count);

		for (auto p = entities; p < entities + count; p++)
		{
			addFilamentAssetNode(p, obj);
		}

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