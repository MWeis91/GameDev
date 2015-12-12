//OpenGL Extension Wrangler
#include<GL\glew.h>

//GLFW
#include<GLFW\glfw3.h>

//OpenGL Mathematics
#include<glm\glm.hpp>
#include<glm\fwd.hpp>
#include<glm\vec3.hpp>
#include<glm\gtc\matrix_transform.hpp>
#include "PerfAnalyzer.h"

#include "Shader.h"
#include "Model.h"
#include "Window.h"
#include "Render.h"

#include <string>
#include <stdio.h>
#include <iostream>
#include <istream>
#include <fstream>
#include <vector>

using namespace std;

int main( int argc, char** argv) {

	cout << "here" << endl;
	Render _R;
	cout << "here"<< endl;
	_R.Initilize(800, 800, "stuff");

	float RotateAngle = 0.0f;


	glm::mat4 MVP[2];
																				//Vector containing the Model, View, and Projection matrix
	glm::mat4 Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
        
    // Camera matrix
    glm::mat4 View = glm::lookAt( glm::vec3(4.0f,3.0f,3.0f),	// Camera is at (4,3,3), in World Space
                                  glm::vec3(0,0,0),				// and looks at the origin
                                  glm::vec3(0,1,0)				// Head is up (set to 0,-1,0 to look upside-down)
                                );
	
	
	Model object("cube2.obj", "CheckerPatternPaper.dds");
	Model object2("sphere2.obj", "blue.dds");
	Model object3("sphere2.obj", "blue.dds");
	Model object4("sphere2.obj", "blue.dds");

	object.updateViewProjection(View, Projection);
	object2.updateViewProjection(View, Projection);
	object3.updateViewProjection(View, Projection);
	object4.updateViewProjection(View, Projection);

	object.modelTransform( glm::mat4(1.0f));
	object.scale(glm::vec3(0.5f, 0.5f, 0.5));

	object2.modelTransform( glm::mat4(1.0f));
	object2.scale(glm::vec3(0.7f, 0.7f, 0.7f));

	object3.modelTransform( glm::mat4(1.0f));
	object3.scale(glm::vec3(0.7f, 0.7f, 0.7f));

	object4.modelTransform( glm::mat4(1.0f));
	object4.scale(glm::vec3(0.7f, 0.7f, 0.7f));

	object.translate(glm::vec3(2.0f, 1.0f, 0.0f));
	object2.translate(glm::vec3(-2.0f, 0.0f, 0.0f));
	object3.translate(glm::vec3(-4.0f, 0.0f, -13.0f));
	object4.translate(glm::vec3(2.0f, -3.0f, -1.0f));

	RotateAngle = 0.0003f;	
	float trans = 0.0003f;

	PerfAnalyzer perf;

	perf.startTest();
	while ( _R.pollExit())															//main loop
	{
		_R.update();


		object.rotate(glm::vec3(1,1,1), RotateAngle);
		object2.translate(glm::vec3(cosf(trans)/400, 0, sinf(trans)/400));

		trans += 0.001f;

		glm::mat4 View = glm::lookAt( glm::vec3(4.0f, 4.0f,4.0f),	// Camera is at (4,3,3), in World Space
                                  glm::vec3(0,0,0),					// and looks at the origin
                                  glm::vec3(0,1,0)					// Head is up (set to 0,-1,0 to look upside-down)
                                );

		object.updateViewProjection(View, Projection);
		object2.updateViewProjection(View, Projection);
		object3.updateViewProjection(View, Projection);
		object4.updateViewProjection(View, Projection);

		_R.drawModel(object);
		_R.drawModel(object2);
		_R.drawModel(object3);
		_R.drawModel(object4);

		perf.incrementDrawCalls();
		perf.incrementDrawCalls();
		perf.incrementDrawCalls();
		perf.incrementDrawCalls();

		_R.updateWindow();
		perf.update();		
	}
	perf.endTest();
	perf.logResults();
	

	_R.end();

	glfwTerminate();

	return 0;
}