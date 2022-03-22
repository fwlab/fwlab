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
	};
}

#endif