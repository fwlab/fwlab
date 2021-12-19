#ifndef FWLAB_LOADER_LOADER_H
#define FWLAB_LOADER_LOADER_H
#include "../object/Mesh.h"
#include "../Context.h"

/// <summary>
/// ¼ÓÔØÆ÷
/// </summary>
class Loader
{
public:
	Loader(Context* context);
	virtual ~Loader();
	Mesh* load();

protected:
	Context* context;
};

#endif