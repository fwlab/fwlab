#ifndef FWLAB_OBJECT_SKYBOX_H
#define FWLAB_OBJECT_SKYBOX_H
#include <filament/Engine.h>
#include <filament/Skybox.h>

/// <summary>
/// Ìì¿ÕºÐ
/// </summary>
class Skybox {
public:
	explicit Skybox(filament::Engine* engine, filament::math::float4 color = { 0.1, 0.125, 0.25, 1.0 }, bool showSun = false);
	explicit Skybox(filament::Engine* engine, filament::Texture* cubemap, float envIntensity = 30000, bool showSun = false);
	virtual ~Skybox();
	filament::Skybox* skybox;

private:
	filament::Engine* engine;
};

#endif