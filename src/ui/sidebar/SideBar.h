#ifndef FWLAB_UI_SIDEBAR_SIDE_BAR_H
#define FWLAB_UI_SIDEBAR_SIDE_BAR_H
#include "../Component.h"
#include "scene/ScenePanel.h"
#include "property/PropertyPanel.h"

namespace fwlab::ui::sidebar
{
	class SideBar : public Component
	{
	public:
		SideBar();
		virtual ~SideBar();
		void render() override;

	private:
		float width = 240;
		float maxWidth = 400;
		float marginTop = 26;
		float sceneHeight = 400;
		scene::ScenePanel* scenePanel = nullptr;
		property::PropertyPanel* propertyPanel = nullptr;
	};
}

#endif