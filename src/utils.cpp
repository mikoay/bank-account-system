#include "utils.h"

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

void pause()
{
#ifdef _WIN32
	system("pause");
#else
	system("read -n 1 -s -p \"Press any key to continue...\"");
#endif
}

std::string get_current_date()
{
    std::time_t t = std::time(nullptr);
    std::tm timeStruct{};
#ifdef _WIN32
    localtime_s(&timeStruct, &t);
#else
    localtime_r(&t, &timeStruct);
#endif
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << timeStruct.tm_mday << "-"
        << std::setw(2) << std::setfill('0') << (timeStruct.tm_mon + 1) << "-"
        << (timeStruct.tm_year + 1900);
    return oss.str();
}

float get_random_float(float min, float max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(min, max);
    float random_value = dist(gen);
    return std::round(random_value * 100.0f) / 100.0f;
}
