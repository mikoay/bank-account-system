#include "utilities.h"

void sleep(unsigned int seconds)
{
#ifdef _WIN32
    Sleep(seconds * 1e3);
#else
    usleep(seconds * 1e6);
#endif
}

void clear()
{
#ifdef _WIN32
    system("cls");
#else
    execlp("clear", "clear", NULL);
#endif
}