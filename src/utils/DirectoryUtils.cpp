#include <filesystem>
#include <Windows.h>
#include "EncodingUtils.h"
#include "DirectoryUtils.h"

namespace fwlab::utils
{
	std::vector<std::string> DirectoryUtils::GetLogicalDrives()
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

	std::vector<std::string> DirectoryUtils::GetChildren(std::string dir, Type type)
	{
		if (!dir.ends_with("\\"))
		{
			return std::vector<std::string>();
		}

		dir += "*";

		wchar_t dirw[MAX_PATH] = {};
		MultiByteToWideChar(CP_UTF8, 0, dir.c_str(), -1, dirw, MAX_PATH);

		std::vector<std::string> result;

		WIN32_FIND_DATAW fd = {};

		HANDLE handle = FindFirstFileW(dirw, &fd);

		while (FindNextFileW(handle, &fd))
		{
			char buf[MAX_PATH] = {};
			WideCharToMultiByte(CP_UTF8, 0, fd.cFileName, -1, buf, MAX_PATH, NULL, NULL);

			if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				if (type != Type::File)
				{
					strcat(buf, "\\");
					result.push_back(buf);
				}
			}
			else
			{
				if (type != Type::Directory)
				{
					result.push_back(buf);
				}
			}
		}

		FindClose(handle);

		return result;
	}
}