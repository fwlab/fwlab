#include <filesystem>
#include <Windows.h>
#include "EncodingUtils.h"
#include "SystemUtils.h"

namespace fwlab::utils
{
	static inline std::string gbkToUtf8(std::string source)
	{
		return EncodingUtils::GBKToUTF8(source.c_str());
	}

	std::vector<std::string> SystemUtils::GetLogicalDrives()
	{
		std::vector<std::string> result;

		DWORD drivers = ::GetLogicalDrives();
		int index = 0;

		while (drivers > 0)
		{
			if ((drivers & 1) > 0)
			{
				result.push_back({ char('A' + index) });
			}

			drivers >>= 1;
			index++;
		}

		return result;
	}

	std::vector<std::string> SystemUtils::GetChildDirectories(std::string path)
	{
		if (!std::filesystem::exists(path))
		{
			return std::vector<std::string>();
		}

		std::vector<std::string> result;

		std::filesystem::directory_iterator end_iter;
		for (std::filesystem::directory_iterator iter(path); iter != end_iter; ++iter)
		{
			try
			{
				if (std::filesystem::is_directory(iter->path()))
				{
					result.push_back(gbkToUtf8(iter->path().generic_string()));
				}
			}
			catch (std::exception& ex)
			{
			}
		}

		return result;
	}

	std::vector<std::string> SystemUtils::GetChildFiles(std::string path)
	{
		if (!std::filesystem::exists(path))
		{
			return std::vector<std::string>();
		}

		std::vector<std::string> result;

		std::filesystem::directory_iterator end_iter;
		for (std::filesystem::directory_iterator iter(path); iter != end_iter; ++iter)
		{
			try
			{
				if (std::filesystem::is_regular_file(iter->path()))
				{
					result.push_back(gbkToUtf8(iter->path().generic_string()));
				}
			}
			catch (std::exception& ex)
			{

			}
		}

		return result;
	}
}