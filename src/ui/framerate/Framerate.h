#ifndef UI_FRAMERATE_FRAMERATE_H
#define UI_FRAMERATE_FRAMERATE_H
#include "../Component.h"

namespace ui::framerate
{
	class Framerate : public Component
	{
	public:
		void render() override;
	};
}

#endif