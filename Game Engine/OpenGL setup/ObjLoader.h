#ifndef OBJ_H
#define OBJ_H

#include <vector>
#include <stdio.h>
#include <string>
#include <cstring>

#include "Object.h"

#include <glm/glm.hpp>

using namespace std;

bool loadOBJ(const char * path, vector<glm::vec3> & out_vertices, vector<glm::vec2> & out_uvs, vector<glm::vec3> & out_normals);	//loats .obj files into the model class
vector<Object> loadTextFile( string filepath);			//returns a vector of objects from a text file of objects

#endif