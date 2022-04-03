#ifndef FWLAB_UTILS_DIRECTORY_UTILS_H
#define FWLAB_UTILS_DIRECTORY_UTILS_H
#include <string>
#include <vector>

namespace fwlab::utils
{
	class DirectoryUtils
	{
	public:
		enum class Type
		{
			All,
			Directory,
			File
		};
		static std::vector<std::string> GetLogicalDrives();
		static std::vector<std::string> GetChildren(std::string dir, Type type = Type::All);
	};
}

#endif