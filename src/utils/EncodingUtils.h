#ifndef FWLAB_UTILS_ENCODING_UTILS_H
#define FWLAB_UTILS_ENCODING_UTILS_H
#include <string>

namespace fwlab::utils
{
	class EncodingUtils
	{
	public:
		static std::string UTF8ToGBK(const std::string& strUTF8);
		static char* GBKToUTF8(const char* chGBK);

	private:
		EncodingUtils() {}
	};
}

#endif