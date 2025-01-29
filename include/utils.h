#pragma once

#include <cstdlib>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <sstream>
#include <iomanip>
#include <ctime>
#include <random>

void sleep(unsigned int seconds);
void clear();
void pause();
std::string get_current_date();
float get_random_float(float min, float max);