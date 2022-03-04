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
		void renderPlots();
		void handleRender(void* data);
		float width = 200;
		float height = 40;

		double lastTime = 0;
		double frameCount = 0;
		double fps = 0;

		static float rates[120];
		int current = 0;
	};
}

#endif