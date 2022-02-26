#ifndef FWLAB_UI_FRAMERATE_FRAMERATE_H
#define FWLAB_UI_FRAMERATE_FRAMERATE_H
#include "../Component.h"

namespace fwlab::ui::framerate
{
	class Framerate : public Component
	{
	public:
		Framerate();
		virtual ~Framerate();
		void render() override;

	private:
		void handleRender(void* data);
		float width = 200;
		float height = 40;

		double lastTime = 0;
		double frameCount = 0;
		double fps = 0;

		float* rates = nullptr;
		int current = 0;
	};
}

#endif