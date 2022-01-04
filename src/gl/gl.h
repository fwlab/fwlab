// core
#include "core/BufferAttribute.h"
#include "core/BufferGeometry.h"
#include "core/Object3D.h"

// geometry
#include "geometry/PlaneGeometry.h"
#include "geometry/BoxGeometry.h"

// material
#include "material/Material.h"
#include "material/StandardMaterial.h"

// object
#include "object/Mesh.h"
#include "object/Skybox.h"

// camera
#include "camera/OrthographicCamera.h"
#include "camera/PerspectiveCamera.h"

// light
#include "light/Light.h"

// loader
#include "loader/Loader.h"
#include "loader/FilameshLoader.h"

namespace gl
{
	using namespace gl::core;
	using namespace gl::geometry;
	using namespace gl::material;
	using namespace gl::object;
	using namespace gl::camera;
	using namespace gl::light;
	using namespace gl::loader;
}