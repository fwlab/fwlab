#include <Windows.h>
#include "SystemUtils.h"

namespace fwlab::utils
{
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
}