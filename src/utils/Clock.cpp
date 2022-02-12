#include <SDL.h>
#include "Clock.h"

using namespace utils;

Clock::Clock(bool autoStart)
{
    this->autoStart = autoStart;

    frequency = SDL_GetPerformanceFrequency();

    this->startTime = 0;
    this->oldTime = 0;
    this->elapsedTime = 0;

    this->running = false;
}

Clock::~Clock()
{
}

void Clock::start()
{
    this->startTime = now();

    this->oldTime = this->startTime;
    this->elapsedTime = 0;
    this->running = true;
}

void Clock::stop()
{
    this->getElapsedTime();
    this->running = false;
    this->autoStart = false;
}

double Clock::getElapsedTime()
{
    this->getDelta();
    return this->elapsedTime;
}

double Clock::getDelta()
{
    double diff = 0;

    if (this->autoStart && !this->running)
    {
        this->start();
        return 0;
    }

    if (this->running)
    {
        double newTime = now();

        diff = newTime - this->oldTime;
        this->oldTime = newTime;

        this->elapsedTime += diff;
    }

    return diff;
}

double Clock::now()
{
    return double(SDL_GetPerformanceCounter()) / frequency;
}