#ifndef FWLAB_UTILS_CLOCK_H
#define FWLAB_UTILS_CLOCK_H
#include <stdint.h>

namespace fwlab::utils
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
		void update();

	private:
		inline double now();
		bool autoStart;
		uint64_t frequency;
		double startTime;
		double oldTime;
		double elapsedTime;
		double deltaTime;
		bool running;
	};
}

#endif