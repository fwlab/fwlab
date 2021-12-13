#ifndef FWLAB_OBJECT_SKYBOX_H
#define FWLAB_OBJECT_SKYBOX_H
#include <filament/Engine.h>
#include <filament/Skybox.h>

/// <summary>
/// Ìì¿ÕºÐ
/// </summary>
class Skybox {
public:
	explicit Skybox(filament::Engine* engine);
	virtual ~Skybox();
	filament::Skybox* skybox;

private:
	filament::Engine* engine;
};

#endif