#include <algorithm>
#include <cmath>
#include <filament/Camera.h>
#include <filament/TransformManager.h>
#include <utils/EntityManager.h>
#include <vector>
#include "../gl/gl.h"
#include "resources/resources.h"
#include "AnimationScene.h"

using namespace gl::core;
using namespace gl::geometry;
using namespace gl::material;
using namespace gl::object;
using namespace gl::light;

std::vector<float> _vertices = { {
		1, 0, 0,
		float(std::cos(M_PI * 2 / 3)), float(std::sin(M_PI * 2 / 3)), 0,
		float(std::cos(M_PI * 4 / 3)), float(std::sin(M_PI * 4 / 3)), 0
} };
std::vector<uint32_t> _colors = { { 0xffff0000u, 0xff00ff00u, 0xff0000ffu } };
std::vector<uint32_t> _indices = { { 0, 1, 2 } };

Skybox* skybox;
Context context;
Mesh* mesh;
utils::Entity cameraEntity;
filament::Camera* camera;

void AnimationScene::setup(filament::Engine* engine, filament::View* view, filament::Scene* scene)
{
	FilamentApp& app = FilamentApp::get();
	context = { &app, engine, view, scene };

	skybox = new Skybox(&context);
	scene->setSkybox(skybox->skybox);

	auto geometry = new BufferGeometry(&context);

	float* vertices = new float[9];
	std::copy(_vertices.begin(), _vertices.end(), vertices);
	auto position = new VertexBufferAttribute(vertices, 3, false);
	position->attribute = filament::VertexAttribute::POSITION;
	position->attributeType = filament::VertexBuffer::AttributeType::FLOAT3;
	position->count = 3;
	geometry->attributes.insert({ filament::VertexAttribute::POSITION, position });

	uint32_t* colors = new uint32_t[3];
	std::copy(_colors.begin(), _colors.end(), colors);
	auto color = new VertexBufferAttribute(colors, 1, true);
	color->attribute = filament::VertexAttribute::COLOR;
	color->attributeType = filament::VertexBuffer::AttributeType::UBYTE4;
	color->count = 3;
	geometry->attributes.insert({ filament::VertexAttribute::COLOR, color });

	uint32_t* indices = new uint32_t[9];
	std::copy(_indices.begin(), _indices.end(), indices);
	auto index = new IndexBufferAttribute(indices, 1);
	index->count = 3;
	geometry->index = index;

	geometry->create();

	auto material = new Material(&context);
	material->create(RESOURCES_BAKEDCOLOR_DATA, RESOURCES_BAKEDCOLOR_SIZE);

	mesh = new Mesh(&context);
	mesh->create(geometry, material);

	scene->addEntity(mesh->entity);

	cameraEntity = utils::EntityManager::get().create();
	camera = engine->createCamera(cameraEntity);
	camera->setProjection(filament::Camera::Projection::ORTHO, -1, 1, -1, 1, -1, 1);
	view->setCamera(camera);
}

void AnimationScene::cleanup(filament::Engine* engine, filament::View* view, filament::Scene* scene)
{
	delete skybox;
	delete mesh;
	engine->destroyCameraComponent(cameraEntity);
	utils::EntityManager::get().destroy(cameraEntity);
}

void AnimationScene::animate(filament::Engine* engine, filament::View* view, double now)
{
	constexpr float ZOOM = 1.5f;
	const uint32_t w = view->getViewport().width;
	const uint32_t h = view->getViewport().height;
	const float aspect = (float)w / h;
	camera->setProjection(filament::Camera::Projection::ORTHO,
		-aspect * ZOOM, aspect * ZOOM,
		-ZOOM, ZOOM, 0, 1);
	auto& tcm = engine->getTransformManager();
	tcm.setTransform(tcm.getInstance(mesh->entity),
		filament::math::mat4f::rotation(now, filament::math::float3{ 0, 0, 1 }));
}
