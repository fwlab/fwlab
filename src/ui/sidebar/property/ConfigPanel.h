#ifndef FWLAB_UI_SIDEBAR_PROPERTY_CONFIG_PANEL_H
#define FWLAB_UI_SIDEBAR_PROPERTY_CONFIG_PANEL_H
#include "../../Component.h"

namespace fwlab::ui::sidebar::property
{
	class ConfigPanel : public Component
	{
	public:
		ConfigPanel();
		virtual ~ConfigPanel();
		void render() override;
	};
}

#endif