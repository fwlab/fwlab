#include "Component.h"

using namespace ui;

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
