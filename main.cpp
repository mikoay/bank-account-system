#include "Application.h"

int main()
{
	Application *Instance = new Application;
	Instance->run();
	delete Instance;
	return 0;
}