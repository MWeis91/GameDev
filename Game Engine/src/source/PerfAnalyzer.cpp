#include <iostream>
#include <fstream>
#include "PerfAnalyzer.h"


PerfAnalyzer::PerfAnalyzer()
{
	frameCount = 0;
	drawCalls = 0;
	collisionChecks = 0;
	elapsedTime = 0;
	minFrames = 1000000;
	maxFrames = 0;
}


float PerfAnalyzer::getMilisecPerFrame()			//returnes the current milisecsPerFrame
{
	return milisecPerFrame;
}

void PerfAnalyzer::startTest()
{
	start = std::chrono::high_resolution_clock::now();
	prev = std::chrono::high_resolution_clock::now();
}

void PerfAnalyzer::update()
{
	frameCount++;				//increment the frame count every update

	if(updateFrames < 100)		//only perform update calculation every 100 frames
	{
		updateFrames++;
	}
	else
	{
		updateFrames = 0;
		curr = std::chrono::high_resolution_clock::now();												
		elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds> (curr-prev).count();
		prev = std::chrono::high_resolution_clock::now();

		milisecPerFrame = float(elapsedTime)/100;
		float framesPerSecond = (1/milisecPerFrame) * 1000;

		std::cout << framesPerSecond << std::endl;

		if(milisecPerFrame > maxFrames)			//check if the current update is the maximum miliseconds per frame
		{
			maxFrames = milisecPerFrame;
		}

		if(milisecPerFrame < minFrames)			//check if the current update is the minimum miliseconds per frame
		{
			if (milisecPerFrame > 0)
				minFrames = milisecPerFrame;
		}

	}
}
void PerfAnalyzer::endTest()
{
	end = std::chrono::high_resolution_clock::now();
	totalTime = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();

	avgFrames = float(totalTime)/float(frameCount);
}

int PerfAnalyzer::getFrameCount()				//return the total number of frames in a simulation
{
	return frameCount;
}
int PerfAnalyzer::getDrawCalls()					//return the total number of draw calls in a simulation
{
	return drawCalls;
}
int PerfAnalyzer::getCollisionChecks()			//return the total number of collision checks in a simulation
{
	return collisionChecks;
}

void PerfAnalyzer::logResults()					//log the min/max/average milisecs per frame from the test
{
	std::ofstream outputFile;
	outputFile.open("PerformanceResults.txt");
	outputFile << "Total number of frames: " << frameCount << "\n"; 
	outputFile << "Total simulation run time: " << totalTime << "ms\n\n";

	outputFile << "Average miliseconds per frame: " << avgFrames << "\n";
	outputFile << "Highest miliseconds per frame: " << maxFrames << "\n";
	outputFile << "Lowest miliseconds per frame: " << minFrames << "\n\n";
	outputFile << "Total number of draw calls: " << drawCalls << "\n";
	outputFile << "Total number of collision checks: " << collisionChecks << "\n";

	outputFile.close();
}

void PerfAnalyzer::incrementDrawCalls()
{
	drawCalls++;
}

void PerfAnalyzer::incrementCollisionChecks()
{
	collisionChecks++;
}