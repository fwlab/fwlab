#include "Component.h"

namespace fwlab::ui
{
	Component::Component()
	{
		static int i = -1;

		id = "Component" + i--;
	}

	Component::~Component()
	{
	}

	void Component::render()
	{
	}

}