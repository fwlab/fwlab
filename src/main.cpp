#include <fstream>
#ifdef WIN32
#include <Windows.h>
#endif
#include "Application.h"

#ifdef WIN32
int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd
)
#else
int main()
#endif
{
	try
	{
		fwlab::Application app;
		app.start();
	}
	catch (std::exception ex)
	{
		std::ofstream out("error.txt");
		out << ex.what() << std::endl;
		out.close();
	}

	return 0;
}