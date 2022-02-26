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
	fwlab::Application app;
	app.start();

	return 0;
}