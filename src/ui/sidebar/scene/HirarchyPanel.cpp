#include <imgui.h>
#include <filament/RenderableManager.h>
#include <filament/TransformManager.h>
#include <utils/EntityManager.h>
#include "HirarchyPanel.h"
#include "../../../context/context.h"

namespace fwlab::ui::sidebar::scene
{

	HirarchyPanel::HirarchyPanel()
	{
	}

	HirarchyPanel::~HirarchyPanel()
	{
	}

	void HirarchyPanel::render()
	{
		if (!this->isInit)
		{
			this->createTree(app->getScene());
		}

		ImGui::TreeNodeEx("透视相机", ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen);
		ImGui::TreeNodeEx("渲染器", ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen);
		ImGui::SetNextTreeNodeOpen(true);
		if (ImGui::TreeNodeEx("场景", ImGuiTreeNodeFlags_Selected))
		{
			ImGui::TreeNodeEx("环境光", ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen);
			ImGui::TreeNodeEx("平行光", ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen);
			ImGui::TreeNodeEx("平面", ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen);
			ImGui::TreeNodeEx("机器狗", ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen);
			ImGui::TreePop();
		}
	}

	void HirarchyPanel::createTree(fwlab::scene::SceneGraph* graph)
	{
		this->isInit = true;

		auto& entityManager = app->getEngine()->getEntityManager();

		// auto &manager = app->getEngine()->getTransformManager();

		// manager.getInstance()
	}
}