#ifndef FWLAB_UI_SIDEBAR_SCENE_HIRARCHY_PANEL_H
#define FWLAB_UI_SIDEBAR_SCENE_HIRARCHY_PANEL_H
#include <string>
#include <vector>
#include "../../Component.h"
#include "../../../core/Object3D.h"

namespace fwlab::ui::sidebar::scene
{
	class HirarchyPanel : public Component
	{
	public:
		HirarchyPanel();
		virtual ~HirarchyPanel();
		void render() override;

	private:
		void createTree(fwlab::core::Object3D* graph);
	};
}

#endif