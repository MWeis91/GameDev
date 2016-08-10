#ifndef PERF_ANALYZER_H
#define PERF_ANALYZER_H

#include <chrono>
#include <ctime>

class PerfAnalyzer
{
public:
	PerfAnalyzer();
	//~PerfAnalyzer();

	float getMilisecPerFrame();			//returnes the current milisecsPerFrame
	float getCurrTime();				//returnes the current time
	int getFrameCount();				//return the total number of frames in a simulation
	int getDrawCalls();					//return the total number of draw calls in a simulation
	int getCollisionChecks();			//return the total number of collision checks in a simulation

	void startTest();					//start the timer
	void update();						//update the analyzer every 100 frames
	void endTest();						//end the timer
	void logResults();					//log the min/max/average milisecs per frame from the test

	void incrementDrawCalls();
	void incrementCollisionChecks();
	void incrementFrameCount();

private:
	std::chrono::time_point<std::chrono::high_resolution_clock> start, end, curr, prev;

	unsigned short int updateFrames;					//number of frames passed before performing an update (updates every 100)

	unsigned long int frameCount;
	unsigned long int drawCalls;
	unsigned long int collisionChecks;

	unsigned long int totalTime;
	unsigned int elapsedTime;

	float milisecPerFrame;

	float minFrames;
	float maxFrames;
	float avgFrames;

};
#endif