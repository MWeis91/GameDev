#ifndef SM_H
#define SM_H

#include <vector>
#include <string>

#include "Model.h"
//#include "MainLoop.h"
#include "Object.h"
#include "ObjLoader.h"
#include "Physics.h"
#include "Shader.h"
#include "PerfAnalyzer.h"
#include "Render.h"

//OpenGL Extension Wrangler
#include<GL\glew.h>

//OpenGL Mathematics
#include<glm\glm.hpp>
#include<glm\fwd.hpp>
#include<glm\vec3.hpp>
#include<glm\gtc\matrix_transform.hpp>


class SceneManager
{
public:
	SceneManager();					//Work in progress. Start the Scene GUI
	~SceneManager();

	void initRendering();
	void loadObjects(string objFP);
	void addObject(const Object &_o);
	void startLoop();
	void stopLoop();

	//Shader getShader();
	//GLuint getProgramID();
	//GLuint getMatID();
	//GLuint getViewMat();

private:
	//MainLoop Loop;
	std::vector<Object> ObjList;
	Render RenderEngine;
	
};
#endif