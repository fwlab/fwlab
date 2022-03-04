#ifndef FWLAB_UTILS_LOGGER_H
#define FWLAB_UTILS_LOGGER_H
#include <fstream>
#include <string>
#include <vector>

namespace fwlab::utils
{
	class Logger
	{
	public:
		enum Level
		{
			INFO,
			WARN,
			ERROR
		};
		Logger(std::string path = "log.txt");
		virtual ~Logger();
		void info(std::string content);
		void warn(std::string content);
		void error(std::string content);
		void log(Level level, std::string content);
		Logger& operator<<(std::string content);
		template <typename T>
		Logger& operator<<(std::vector<T> vector);

	private:
		std::ofstream out;
	};
}

#endif