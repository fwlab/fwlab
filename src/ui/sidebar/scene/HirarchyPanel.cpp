#include <imgui.h>
#include <filament/RenderableManager.h>
#include <filament/TransformManager.h>
#include <utils/EntityManager.h>
#include "HirarchyPanel.h"
#include "../../../context/context.h"

constexpr auto TreeLeafFlags = ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen;

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
		ImGui::TreeNodeEx("透视相机", TreeLeafFlags);
		ImGui::TreeNodeEx("渲染器", TreeLeafFlags);
		ImGui::TreeNodeEx("环境光", TreeLeafFlags);
		ImGui::SetNextTreeNodeOpen(true);
		createTree(app->getScene());
	}

	void HirarchyPanel::createTree(fwlab::core::Object3D* node)
	{
		auto children = node->getChildren();
		auto name = node->getName();
		if (name.empty())
		{
			name = "未命名";
		}

		if (children.size() > 0)
		{
			if (ImGui::TreeNode(name.c_str()))
			{
				for (auto child : children)
				{
					createTree(child);
				}

				ImGui::TreePop();
			}
		}
		else
		{
			ImGui::TreeNodeEx(name.c_str(), TreeLeafFlags);
		}
	}
}