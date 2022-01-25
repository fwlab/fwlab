#include "gl.h"

namespace gl
{
	void init(filament::Engine *engine, filament::View *view, filament::Scene *scene)
	{
		gl::context::engine = engine;
		gl::context::view = view;
		gl::context::scene = scene;
	}
}