#ifndef FWLAB_UI_MENUBAR_EXPERIMENT_MENU_H
#define FWLAB_UI_MENUBAR_EXPERIMENT_MENU_H
#include "../Component.h"

namespace fwlab::ui::menubar
{
	class ExperimentMenu : public Component
	{
	public:
		void render() override;
	};
}

#endif