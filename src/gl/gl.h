#include <filament/Engine.h>
#include <filament/View.h>
#include <filament/Scene.h>
#include <filamentapp/FilamentApp.h>

#include "context/context.h"

#include "core/BufferAttribute.h"
#include "core/BufferGeometry.h"
#include "core/Object3D.h"

#include "geometry/PlaneGeometry.h"
#include "geometry/BoxGeometry.h"

#include "material/Material.h"
#include "material/LitMaterial.h"
#include "material/SubsurfaceMaterial.h"
#include "material/ClothMaterial.h"
#include "material/UnlitMaterial.h"
#include "material/SpecularGlossinessMaterial.h"

#include "object/Mesh.h"
#include "object/Skybox.h"

#include "camera/OrthographicCamera.h"
#include "camera/PerspectiveCamera.h"

#include "light/Light.h"

#include "loader/Loader.h"
#include "loader/FilameshLoader.h"

namespace gl
{
	using namespace gl::context;
	using namespace gl::core;
	using namespace gl::geometry;
	using namespace gl::material;
	using namespace gl::object;
	using namespace gl::camera;
	using namespace gl::light;
	using namespace gl::loader;

	void init(FilamentApp* app, filament::Engine* engine, filament::View* view, filament::Scene* scene);
}