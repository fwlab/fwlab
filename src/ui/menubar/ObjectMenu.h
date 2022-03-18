#ifndef FWLAB_UI_MENUBAR_OBJECT_MENU_H
#define FWLAB_UI_MENUBAR_OBJECT_MENU_H
#include "../Component.h"

namespace fwlab::ui::menubar
{
	class ObjectMenu : public Component
	{
	public:
		void render() override;

	private:
		void addPlane();
	};
}

#endif