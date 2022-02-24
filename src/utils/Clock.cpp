#include <SDL.h>
#include "Clock.h"

using namespace utils;

Clock::Clock(bool autoStart)
{
	this->autoStart = autoStart;

	frequency = SDL_GetPerformanceFrequency();

	startTime = 0;
	oldTime = 0;
	elapsedTime = 0;
	deltaTime = 0;

	running = false;
}

Clock::~Clock()
{
}

void Clock::start()
{
	startTime = now();

	oldTime = startTime;
	elapsedTime = 0;
	deltaTime = 0;
	running = true;
}

void Clock::stop()
{
	update();
	running = false;
	autoStart = false;
}

double Clock::getElapsedTime()
{
	return elapsedTime;
}

double Clock::getDelta()
{
	return deltaTime;
}

void Clock::update()
{
	if (autoStart && !running)
	{
		start();
	}
	if (!running)
	{
		return;
	}

	double newTime = now();
	deltaTime = newTime - oldTime;
	oldTime = newTime;

	elapsedTime += deltaTime;
}

double Clock::now()
{
	return double(SDL_GetPerformanceCounter()) / frequency;
}