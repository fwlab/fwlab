#ifndef FWLAB_APPLICATION_H
#define FWLAB_APPLICATION_H
#include <filamentapp/Config.h>

/// <summary>
/// Ӧ�ó���
/// </summary>
class Application {
public:
	explicit Application();
	virtual ~Application();
	void start();
	void stop();
private:
	Config config;
};

#endif