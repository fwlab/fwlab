#include <iterator>
#include "TimeUtils.h"
#include "Logger.h"

using namespace utils;

Logger::Logger(std::string path)
{
	out = std::ofstream(path);
}

Logger::~Logger()
{
	out.close();
}

void Logger::info(std::string content)
{
	log(INFO, content);
}

void Logger::warn(std::string content)
{
	log(WARN, content);
}

void Logger::error(std::string content)
{
	log(ERROR, content);
}

void Logger::log(Level level, std::string content)
{
	const char *levelNames[] = {"INFO", "WARN", "ERROR"};

	out << TimeUtils::getCurrentTime()
		<< " [" << levelNames[static_cast<int>(level)] << "] "
		<< content << std::endl;
}

Logger &Logger::operator<<(std::string content)
{
	out << content;
	return *this;
}

template <typename T>
Logger &Logger::operator<<(std::vector<T> vector)
{
	std::ostream_iterator<T, char> out_iter(out, ", ");
	std::copy(vector.begin(), vector.end(), out_iter);
	return *this;
}

template Logger &Logger::operator<<(std::vector<float> vector);
template Logger &Logger::operator<<(std::vector<double> vector);
template Logger &Logger::operator<<(std::vector<uint16_t> vector);
template Logger &Logger::operator<<(std::vector<uint32_t> vector);