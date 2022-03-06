#ifndef FWLAB_UI_WINDOW_MESSAGE_H
#define FWLAB_UI_WINDOW_MESSAGE_H
#include "../Component.h"

namespace fwlab::ui::window
{
	class Message : public Component
	{
	public:
		Message();
		virtual ~Message();
		void render() override;
	};
}

#endif