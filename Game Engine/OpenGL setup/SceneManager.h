#ifndef SM_H
#define SM_H

#include <vector>
#include <string>

#include "Model.h"
//#include "MainLoop.h"
#include "Object.h"
#include "ObjLoader.h"

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

	void loadObjects(string objFP);
	void addObject(const Object &_o);


private:
	std::vector<Object> ObjList;
	
};
#endif