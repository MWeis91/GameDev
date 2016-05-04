#include "Clock.h"

Clock::Clock()
{
	frequency = 0;
	counterStart = 0;
}
void Clock::startCounter()
{
	LARGE_INTEGER li;
	if(!QueryPerformanceFrequency(&li))
		exit(0);
	
	frequency = double(li.QuadPart);

	QueryPerformanceCounter(&li);
	counterStart = li.QuadPart;
}

float Clock::timeDifference()
{
	/*
	setCurrTime();
	float ticks = std::chrono::duration_cast<std::chrono::milliseconds>(currTime-prevTime).count();
	return ticks * 0.0001f;
	*/
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	float output = float(li.QuadPart - counterStart)/frequency;
	counterStart = li.QuadPart;
	return output;
}

void Clock::setCurrTime()
{
	currTime = std::chrono::high_resolution_clock::now();
}

void Clock::setPrevTime()
{
	prevTime = std::chrono::high_resolution_clock::now();
}

