#ifndef FWLAB_UI_WINDOW_PROMPT_H
#define FWLAB_UI_WINDOW_PROMPT_H
#include "../Component.h"

namespace fwlab::ui::window
{
	class Prompt : public Component
	{
	public:
		Prompt();
		virtual ~Prompt();
		void render() override;
	};
}

#endif