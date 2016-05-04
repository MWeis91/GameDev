#ifndef CLOCK_H
#define CLOCK_H

#include <chrono>
#include <Windows.h>
#include <ctime>

class Clock
{
public:
	Clock();
	void setCurrTime();
	void setPrevTime();
	void startCounter();
	std::chrono::time_point<std::chrono::high_resolution_clock> getCurrentTime();
	float timeDifference();
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> currTime, prevTime;
	double frequency;
	__int64 counterStart;
};
#endif