#ifndef UTILS_CLOCK_UTILS_H
#define UTILS_CLOCK_UTILS_H
#include <stdint.h>

namespace utils
{
    class Clock
    {
    public:
        Clock(bool autoStart = true);
        virtual ~Clock();
        void start();
        void stop();
        double getElapsedTime();
        double getDelta();

    private:
        inline double now();
        bool autoStart;
        uint64_t frequency;
        double startTime;
        double oldTime;
        double elapsedTime;
        bool running;
    };
}

#endif