#ifndef FWLAB_UI_SIDEBAR_SCENE_SCENE_PANEL_H
#define FWLAB_UI_SIDEBAR_SCENE_SCENE_PANEL_H
#include "../../Component.h"
#include "HirarchyPanel.h"
#include "HistoryPanel.h"

namespace fwlab::ui::sidebar::scene
{
	class ScenePanel : public Component
	{
	public:
		ScenePanel();
		virtual ~ScenePanel();
		void render() override;

	private:
		HirarchyPanel* hirarchyPanel = nullptr;
		HistoryPanel* historyPanel = nullptr;
		bool isSceneTabShow = true;
		bool isHistoryTabShow = false;
	};
}

#endif