#ifndef MODEL_H
#define MODEL_H

#include <cstring>
#include <vector>
#include <stdio.h>

//OpenGL Extension Wrangler
#include<GL\glew.h>

#include <GLFW\glfw3.h>
//OpenGL Mathematics
#include<glm\glm.hpp>
#include<glm\fwd.hpp>
#include<glm\vec3.hpp>
#include<glm\gtc\matrix_transform.hpp>

using namespace std;

class Model
{
public:
	Model();//default constructor
	//load the model from the specified obj and texture filepaths
	Model(	const string& objPath, 
			const string& texturePath);

	~Model();//default destructor. delete the buffers

	int initBuffers(	const vector<glm::vec3>& vertices,		//initilize the vertex, uv, and normal buffers
						const vector<glm::vec2>& uv, 
						const vector<glm::vec3>& normal);

	//draw the model using the objects buffers and model matrix. Also pass in the shader programs
	void draw(	const GLuint& programID,
				const GLuint& textureID,
				const GLuint& lightProgram,
				const GLuint& MVPID,
				const GLuint& modelID,
				const GLuint& viewID);
	
	GLuint loadTexture(const string& filepath);				//load the DDS file
	bool loadObject(const string& filepath,					//load the vertex, uv, and normal data from an OBJ file
					vector<glm::vec3>& vertices,
					vector<glm::vec2>& uv,
					vector<glm::vec3>& normal);				

	//transform functions for the model matrix
	void modelTransform(const glm::mat4& model);			//Set the model matrix
	void updateViewProjection(const glm::mat4& view, 
							  const glm::mat4& projection);
	void rotate(const glm::vec3& axis, 
				const float& delta);						//Rotate the model
	void scale(const glm::vec3& scaling);					//Scale the model
	void translate(const glm::vec3& translate);				//Translate the model

private:
	GLuint VBO;										//Vertext buffer
	GLuint UVBuffer;								//UV buffer
	GLuint normalBuffer;							//Normal buffer
	GLuint textureDDS;								//Texture data
	glm::mat4 modelMatrix;							//Model matrix for position of our object
	glm::mat4 viewMatrix;							//view matrix for the camera
	glm::mat4 projectionMatrix;						//projection matrix for flattening
	int vertexAmount;								//number of vertices to be rendered
};

#endif