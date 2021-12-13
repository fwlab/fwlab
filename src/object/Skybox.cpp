#include "Skybox.h"

Skybox::Skybox(filament::Engine* engine)
{
	this->engine = engine;

	skybox = filament::Skybox::Builder()
		.color({ 0.1, 0.125, 0.25, 1.0 })
		.build(*engine);
}

Skybox::~Skybox()
{
	engine->destroy(skybox);
}