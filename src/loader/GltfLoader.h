#ifndef FWLAB_LOADER_GLTF_LOADER_H
#define FWLAB_LOADER_GLTF_LOADER_H
#include <gltfio/AssetLoader.h>
#include <gltfio/FilamentAsset.h>
#include <gltfio/MaterialProvider.h>
#include <gltfio/ResourceLoader.h>
#include <utils/NameComponentManager.h>
#include <utils/Path.h>
#include "../utils/Logger.h"

namespace fwlab::loader
{
	class GltfLoader
	{
	public:
		GltfLoader();
		virtual ~GltfLoader();
		gltfio::FilamentAsset* load(::utils::Path path);
		void update();
		bool isLoaded();
		bool destroyAsset(gltfio::FilamentAsset* assets);
		void destroy();

	private:
		gltfio::MaterialProvider* materialProvider = nullptr;
		::utils::NameComponentManager* names = nullptr;
		gltfio::AssetLoader* assetLoader = nullptr;
		gltfio::ResourceConfiguration configuration;
		gltfio::FilamentAsset* asset = nullptr;
		gltfio::ResourceLoader* resourceLoader = nullptr;
		utils::Logger* log = nullptr;
	};
}

#endif