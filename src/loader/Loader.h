#ifndef FWLAB_LOADER_LOADER_H
#define FWLAB_LOADER_LOADER_H
#include "../object/Mesh.h"

namespace fwlab::loader
{
	class Loader
	{
	public:
		Loader() = default;
		virtual ~Loader() = default;
	};
}

#endif