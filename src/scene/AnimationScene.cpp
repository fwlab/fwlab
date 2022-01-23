#include <algorithm>
#include <cmath>
#include <filament/Camera.h>
#include <filament/TransformManager.h>
#include <utils/EntityManager.h>
#include <vector>
#include "../gl/gl.h"
#include "resources/resources.h"
#include "AnimationScene.h"

std::vector<float> _vertices = {{1, 0, 0,
								 float(std::cos(M_PI * 2 / 3)), float(std::sin(M_PI * 2 / 3)), 0,
								 float(std::cos(M_PI * 4 / 3)), float(std::sin(M_PI * 4 / 3)), 0}};
std::vector<uint32_t> _colors = {{0xffff0000u, 0xff00ff00u, 0xff0000ffu}};
std::vector<uint32_t> _indices = {{0, 1, 2}};

gl::OrthographicCamera *camera;
gl::Skybox *skybox;
gl::Mesh *mesh;

void AnimationScene::setup(filament::Engine *engine, filament::View *view, filament::Scene *scene)
{
	FilamentApp &app = FilamentApp::get();
	gl::init(&app, engine, view, scene);

	camera = new gl::OrthographicCamera();
	view->setCamera(camera->camera);

	skybox = new gl::Skybox();
	scene->setSkybox(skybox->skybox);

	auto geometry = new gl::BufferGeometry();

	float *vertices = new float[9];
	std::copy(_vertices.begin(), _vertices.end(), vertices);
	auto position = new gl::VertexBufferAttribute(vertices, 3, 9);
	geometry->attributes.insert({filament::VertexAttribute::POSITION, position});

	uint32_t *colors = new uint32_t[3];
	std::copy(_colors.begin(), _colors.end(), colors);
	auto color = new gl::VertexBufferAttribute(colors, 1, 3, filament::VertexBuffer::AttributeType::UBYTE4);
	geometry->attributes.insert({filament::VertexAttribute::COLOR, color});

	geometry->index = new gl::IndexBufferAttribute(_indices);

	geometry->create();

	auto material = new gl::Material(RESOURCES_BAKEDCOLOR_DATA, RESOURCES_BAKEDCOLOR_SIZE);

	mesh = new gl::Mesh();
	mesh->create(geometry, material);

	scene->addEntity(mesh->entity);
}

void AnimationScene::cleanup(filament::Engine *engine, filament::View *view, filament::Scene *scene)
{
	delete mesh;
	delete skybox;
	delete camera;
}

void AnimationScene::animate(filament::Engine *engine, filament::View *view, double now)
{
	mesh->setRotation(now, filament::math::float3{0, 0, 1});
}
