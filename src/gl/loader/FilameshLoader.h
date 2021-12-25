#ifndef FWLAB_LOADER_FILAMESH_LOADER_H
#define FWLAB_LOADER_FILAMESH_LOADER_H
#include <filament/MaterialInstance.h>
#include "Loader.h"
#include "../Context.h"

/// <summary>
/// Filamesh¼ÓÔØÆ÷
/// </summary>
class FilameshLoader : public Loader
{
public:
	FilameshLoader(Context* context);
	virtual ~FilameshLoader();
	Mesh* load(void const* data, filament::MaterialInstance* defaultMaterial);
};

#endif