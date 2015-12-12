#include <iostream>
#include <fstream>
#include <sstream>
#include "SceneManager.h"

std::vector<std::string> &split(const std::string &str, char delim, std::vector<std::string> &list)//function used for splitting strings by a specified delimeter
{
	std::stringstream ss(str);
	std::string item;
	while(std::getline(ss, item, delim))
	{
		list.push_back(item);
	}
	return list;
}

std::vector<std::string> split(const std::string &s, char delim) 
{
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

//string split function found from answer to stack-overflow question "http://stackoverflow.com/questions/236129/split-a-string-in-c"


SceneManager::SceneManager()
{

}

void SceneManager::loadObjects(string objectFilePath)//WIP
{
	string line;
	string objPath;
	string objPosStr;
	glm::vec3 pos, scale, rotation = glm::vec3 (0.0f, 0.0f, 0.0f);
	float x,y,z;
	Object tmpObj;

	std::ifstream file;
	file.open(objectFilePath);

	std::vector<std::string> lineSplit;

	while( std::getline(file, line))	
	{
		lineSplit = split(line, ' ');
		string objPath = lineSplit.front();

		lineSplit.pop_back();//discard rotation and scaling for now
		lineSplit.pop_back();

		objPosStr = lineSplit.back();//store the x,y,z pos coords in a new string
		lineSplit = split(objPosStr, ',');//split the coordinates by the new delimeter

		z = stof(lineSplit.back());
		lineSplit.pop_back();
		y = stof(lineSplit.back());
		lineSplit.pop_back();
		x = stof(lineSplit.back());
		lineSplit.pop_back();

		pos = glm::vec3(x, y, z);

		tmpObj.translate(pos);
		ObjList.push_back(tmpObj);

	}
}

void SceneManager::initRendering()
{
	RenderEngine.Initilize(800,800, "Test");
}

void SceneManager::addObject(const Object &_o)
{
	ObjList.push_back(_o);
}