#ifndef FWLAB_UTILS_SYSTEM_UTILS_H
#define FWLAB_UTILS_SYSTEM_UTILS_H
#include <string>
#include <vector>

namespace fwlab::utils
{
	class SystemUtils
	{
	public:
		static std::vector<std::string> GetLogicalDrives();
		static std::vector<std::string> GetChildDirectories(std::string path);
		static std::vector<std::string> GetChildFiles(std::string path);
	};
}

#endif