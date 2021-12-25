#include "Loader.h"

using namespace gl::object;
using namespace gl::loader;

Loader::Loader(Context* context)
{
	this->context = context;
}

Loader::~Loader()
{
}

Mesh* Loader::load()
{
	return nullptr;
}