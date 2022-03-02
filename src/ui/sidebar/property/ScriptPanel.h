#ifndef FWLAB_UI_SIDEBAR_PROPERTY_SCRIPT_PANEL_H
#define FWLAB_UI_SIDEBAR_PROPERTY_SCRIPT_PANEL_H
#include "../../Component.h"

namespace fwlab::ui::sidebar::property
{
	class ScriptPanel : public Component
	{
	public:
		ScriptPanel();
		virtual ~ScriptPanel();
		void render() override;
	};
}

#endif