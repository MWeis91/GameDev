//Needs precompiled structure of objects
#ifndef LOOP_H
#define LOOP_H

//OpenGL Extension Wrangler
#include<GL\glew.h>

//GLFW
#include<GLFW\glfw3.h>

#include "Object.h"
#include "Render.h"
#include "PerfAnalyzer.h"

#include <vector>

class MainLoop
{
public:
	MainLoop();//Default Constructor
	~MainLoop();//Destructor

	void loadObjects(string filepath);

	void RunLoop(Render &RendEngine, vector<Object> &objList);				//Run the main loop
	float DeltaTime(float t);	//return the change in time between a frame
	double getCurrTime();

private:
	//const double dt = 0.01;		//time step (1/100 s)
	PerfAnalyzer perf;
	float time;
};
#endif