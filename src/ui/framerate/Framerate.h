#ifndef UI_FRAMERATE_FRAMERATE_H
#define UI_FRAMERATE_FRAMERATE_H
#include "../Component.h"

namespace ui::framerate
{
	class Framerate : public Component
	{
	public:
		Framerate();
		virtual ~Framerate();
		void render() override;

	private:
		void handleRender(void* data);
		float width = 240;
		float height = 40;
		float* rates = nullptr;
		int current = 0;
	};
}

#endif