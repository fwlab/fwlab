#include "gl.h"

namespace gl
{
	void init(FilamentApp* app, filament::Engine* engine, filament::View* view, filament::Scene* scene)
	{
		gl::context::app = app;
		gl::context::engine = engine;
		gl::context::view = view;
		gl::context::scene = scene;
	}
}