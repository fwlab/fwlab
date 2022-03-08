#ifndef FWLAB_UI_SIDEBAR_SCENE_HIRARCHY_PANEL_H
#define FWLAB_UI_SIDEBAR_SCENE_HIRARCHY_PANEL_H
#include <string>
#include <vector>
#include "../../Component.h"
#include "../../../scene/SceneGraph.h"

namespace fwlab::ui::sidebar::scene
{
	struct TreeNode
	{
		std::string text;
		std::vector<TreeNode*> children;
	};

	class HirarchyPanel : public Component
	{
	public:
		HirarchyPanel();
		virtual ~HirarchyPanel();
		void render() override;

	private:
		void createTree(fwlab::scene::SceneGraph* graph);
		bool isInit = false;
		TreeNode* tree = nullptr;
	};
}

#endif