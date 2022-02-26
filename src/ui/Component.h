#ifndef FWLAB_UI_COMPONENT_H
#define FWLAB_UI_COMPONENT_H
#include <string>

namespace fwlab::ui
{
	class Component
	{
	public:
		Component();
		virtual ~Component();
		virtual void render();

	protected:
		std::string id;
	};
}

#endif