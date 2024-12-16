#pragma once
#include <cstdlib>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

void sleep(unsigned int seconds);
void clear();