#ifndef FWLAB_UI_SIDEBAR_PROPERTY_PROPERTY_PANEL_H
#define FWLAB_UI_SIDEBAR_PROPERTY_PROPERTY_PANEL_H
#include "../../Component.h"
#include "ConfigPanel.h"
#include "ScriptPanel.h"

namespace fwlab::ui::sidebar::property
{
	class PropertyPanel : public Component
	{
	public:
		PropertyPanel();
		virtual ~PropertyPanel();
		void render() override;

	private:
		ConfigPanel* configPanel = nullptr;
		ScriptPanel* scriptPanel = nullptr;
		bool isConfigTabShow = true;
		bool isScriptTabShow = false;
	};
}

#endif