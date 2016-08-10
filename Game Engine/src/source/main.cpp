//OpenGL Mathematics
#include<glm\glm.hpp>
#include<glm\fwd.hpp>
#include<glm\vec3.hpp>
#include<glm\gtc\matrix_transform.hpp>

#include "PerfAnalyzer.h"
#include "Model.h"
#include "Render.h"
#include "Object.h"
#include "DynamicObject.h"
#include "Clock.h"

#include <string>
#include <stdio.h>
#include <iostream>
#include <istream>
#include <fstream>
#include <vector>
#include <time.h>
#include <Windows.h>

using namespace std;

int main( int argc, char** argv) {

	Render RenderEngine;

	RenderEngine.Initilize(800, 800, "Early Dev Test");

	glm::mat4 MVP[2];
																				//Vector containing the Model, View, and Projection matrix
	glm::mat4 Projection = glm::perspective(90.0f, 4.0f / 4.0f, 0.1f, 120.0f);
        
    // Camera matrix
    glm::mat4 View = glm::lookAt( glm::vec3(10.0f,0.0f,0.0f),	// Camera is at (4,3,3), in World Space
                                  glm::vec3(0,-10.0f,0),		// and looks at the origin
                                  glm::vec3(0,1,0)				// Head is up (set to 0,-1,0 to look upside-down)
                                );
	
	
	Model object("./models/sphere.obj", "./models/CheckerPatternPaper.dds");
	object.updateViewProjection(View, Projection);
	object.modelTransform( glm::mat4(1.0f));
	object.scale(glm::vec3(1.0f, 1.0f, 1.0f));

	Model floor("./models/cube2.obj", "./models/CheckerPatternPaper.dds");
	floor.updateViewProjection(View, Projection);
	floor.modelTransform(glm::mat4(1.0f));
	floor.translate(glm::vec3(-50, -40.0f, 0));
	floor.scale(glm::vec3(100, 1, 100));
	

	

	PerfAnalyzer perf;
	Clock timer;

	DynamicObject o;
	o.LoadModel(object);
	State s;
	s.setPosition(glm::vec3 (0, 0, 0));
	s.setMomentum(glm::vec3(0.0f, 0.0f, 0.0f));
	s.setAngularMomentum(glm::vec3(0.0f, 0.0f, 0.0f));
	s.setOrientation(glm::quat(1.0f, 0.0f, 0.0f, 0.0f));
	s.setMass(200.0f);
	//s.setSpin(glm::quat(1.0f, 0.0, 0.0, 1.0));
	s.recalculate();
	o.setCurrentState(s);
	const float dt = 0.01f;
	float t = 0.0f;
	float frameTime = 0.0f;
	float accumulator = 0.0f;

	perf.startTest();
	//timer.setPrevTime();
	timer.startCounter();

	while ( RenderEngine.pollExit())															//main loop
	{
		t = 0.0f;
		RenderEngine.update();
		float frameTime = timer.timeDifference();
		
		while (frameTime < dt )						//if the engine is running faster than dt, stall until the frame time is greater than dt
		{
			frameTime += timer.timeDifference();
		}				
		if( frameTime > 0.25f)						//if the engine is running too slow, slow down the frame time so that the physics simulation does not fall behind
		{
			frameTime = 0.25;
		}
	

		accumulator += frameTime;

		while (accumulator >= dt)
		{
			o.update(t, dt);
			t +=dt;
			accumulator -= dt;
		}

		float alpha = accumulator / dt;

		o.render(alpha);

		o.updateViewProjection(View, Projection);
		floor.updateViewProjection(View, Projection);

		RenderEngine.drawModel(o.getModel());
		RenderEngine.drawModel(floor);

		perf.incrementDrawCalls();

		RenderEngine.updateWindow();
		perf.update();		
	}
	perf.endTest();
	perf.logResults();
	
	RenderEngine.end();
	glfwTerminate();

	return 0;
}