#ifndef FWLAB_UTILS_DIRECTORY_UTILS_H
#define FWLAB_UTILS_DIRECTORY_UTILS_H
#include <string>
#include <vector>

namespace fwlab::utils
{
	class DirectoryUtils
	{
	public:
		static std::vector<std::string> GetLogicalDrives();
		static std::vector<std::string> GetChildren(std::string dir);
	};
}

#endif