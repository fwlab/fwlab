#ifndef FWLAB_UI_WINDOW_CONFIRM_H
#define FWLAB_UI_WINDOW_CONFIRM_H
#include "../Component.h"

namespace fwlab::ui::window
{
	class Confirm : public Component
	{
	public:
		Confirm();
		virtual ~Confirm();
		void render() override;
	};
}

#endif