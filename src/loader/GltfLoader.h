#ifndef FWLAB_LOADER_GLTF_LOADER_H
#define FWLAB_LOADER_GLTF_LOADER_H
#include <functional>
#include <sstream>
#include <string>
#include <vector>
#include <gltfio/AssetLoader.h>
#include <gltfio/FilamentAsset.h>
#include <gltfio/MaterialProvider.h>
#include <gltfio/ResourceLoader.h>
#include <utils/NameComponentManager.h>
#include <utils/Path.h>

namespace fwlab::loader
{
	class GltfLoader
	{
	public:
		GltfLoader();
		virtual ~GltfLoader();
		void load(
			::utils::Path path,
			std::function<void(gltfio::FilamentAsset*)> onLoad,
			std::function<void(float)> onProgress = nullptr,
			std::function<void(std::string)> onError = nullptr
		);
		bool destroyAsset(gltfio::FilamentAsset* asset);

	private:
		enum class Type
		{
			Json,
			Binary
		};

		class LoadData
		{
		public:
			bool load(::utils::Path& path);
			float update();
			void destroy();
			Type getType() const;
			gltfio::ResourceConfiguration getConfiguration() const;
			gltfio::MaterialProvider* getMaterialProvider() const;
			::utils::NameComponentManager* getNameComponentManager() const;
			gltfio::AssetLoader* getAssetLoader() const;
			gltfio::FilamentAsset* getAsset() const;
			gltfio::ResourceLoader* getResourceLoader() const;
			std::function<void(gltfio::FilamentAsset*)> getOnLoad() const;
			void setOnLoad(std::function<void(gltfio::FilamentAsset*)> callback);
			std::function<void(float)> getOnProgress() const;
			void setOnProgress(std::function<void(float)> callback);
			std::function<void(std::string)> getOnError() const;
			void setOnError(std::function<void(std::string)> callback);
			std::string getError();

		private:
			bool createAssetFromFile(::utils::Path& path);
			::utils::Path path;
			Type type = Type::Json;
			gltfio::ResourceConfiguration configuration = {};
			gltfio::MaterialProvider* materialProvider = nullptr;
			::utils::NameComponentManager* nameComponentManager = nullptr;
			gltfio::AssetLoader* assetLoader = nullptr;
			gltfio::FilamentAsset* asset = nullptr;
			gltfio::ResourceLoader* resourceLoader = nullptr;
			std::function<void(gltfio::FilamentAsset*)> onLoad = nullptr;
			std::function<void(float)> onProgress = nullptr;
			std::function<void(std::string)> onError = nullptr;
			std::ostringstream error;
		};

		void handleAnimate(void* data);
		std::vector<LoadData*> loading;
		std::vector<LoadData*> loaded;
	};
}

#endif 