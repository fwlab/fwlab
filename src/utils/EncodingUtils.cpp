#ifdef _WIN32
#include <Windows.h>
#endif
#include "EncodingUtils.h"

// view: https ://blog.csdn.net/weixin_43333380/article/details/108010546
#ifdef _WIN32
std::string EncodingUtils::UTF8ToGBK(const std::string &strUTF8)
{
	int len = MultiByteToWideChar(CP_UTF8, 0, strUTF8.c_str(), -1, NULL, 0);
	wchar_t *wszGBK = new wchar_t[len + 1];
	wmemset(wszGBK, 0, long(len) + 1);
	MultiByteToWideChar(CP_UTF8, 0, (LPCTSTR)strUTF8.c_str(), -1, wszGBK, len);

	len = WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, NULL, 0, NULL, NULL);
	char *szGBK = new char[len + 1];
	memset(szGBK, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, szGBK, len, NULL, NULL);
	//strUTF8 = szGBK;
	std::string strTemp(szGBK);
	delete[] szGBK;
	delete[] wszGBK;
	return strTemp;
}

char *EncodingUtils::GBKToUTF8(const char *chGBK)
{
	DWORD dWideBufSize = MultiByteToWideChar(CP_ACP, 0, (LPCSTR)chGBK, -1, NULL, 0);
	wchar_t *pWideBuf = new wchar_t[dWideBufSize];
	wmemset(pWideBuf, 0, dWideBufSize);
	MultiByteToWideChar(CP_ACP, 0, (LPCSTR)chGBK, -1, pWideBuf, dWideBufSize);

	DWORD dUTF8BufSize = WideCharToMultiByte(CP_UTF8, 0, (LPCWSTR)pWideBuf, -1, NULL, 0, NULL, NULL);

	char *pUTF8Buf = new char[dUTF8BufSize];
	memset(pUTF8Buf, 0, dUTF8BufSize);
	WideCharToMultiByte(CP_UTF8, 0, (LPCWSTR)pWideBuf, -1, pUTF8Buf, dUTF8BufSize, NULL, NULL);

	delete[] pWideBuf;
	return pUTF8Buf;
}
#endif