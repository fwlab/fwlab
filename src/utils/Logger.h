#ifndef UTILS_LOG_UTILS_H
#define UTILS_LOG_UTILS_H
#include <fstream>
#include <string>
#include <vector>

namespace utils
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
		Logger &operator<<(std::string content);
		template <typename T>
		Logger &operator<<(std::vector<T> vector);

	private:
		std::ofstream out;
	};
}

#endif