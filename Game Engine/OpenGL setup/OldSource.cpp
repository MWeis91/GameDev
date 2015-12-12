/*
//OpenGL Extension Wrangler
#include<GL\glew.h>

//GLFW
#include<GLFW\glfw3.h>

//OpenGL Mathematics
#include<glm\glm.hpp>
#include<glm\fwd.hpp>
#include<glm\vec3.hpp>
#include<glm\gtc\matrix_transform.hpp>

#include "Texture.hpp"
#include "Object.h"
#include "Shader.h"
#include "Model.h"

#include <string>
#include <stdio.h>
#include <iostream>
#include <istream>
#include <fstream>
#include <vector>

using namespace std;

//buffers declaired global for use in multiple functions
GLuint VBO;				//vertex buffer object
GLuint uvbuffer;		//uv buffer
GLuint normalbuffer;	//normal buffer


static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)//polls for escape character
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

void CameraMatrix(GLuint _p, GLuint &MVPID, GLuint &ViewMatrixID, GLuint &ModelMatrixID, float f)//gives us our Model/View/Projection Matrix for the camera
{
    // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
    glm::mat4 Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
        
    // Camera matrix
    glm::mat4 View = glm::lookAt( glm::vec3(4.0f,3.0f,3.0f),	// Camera is at (4,3,3), in World Space
                                  glm::vec3(0,0,0),				// and looks at the origin
                                  glm::vec3(0,1,0)				// Head is up (set to 0,-1,0 to look upside-down)
                                );

    // Model matrix : an identity matrix (model will be at the origin)
    glm::mat4 Model      = glm::mat4(1.0f);					//scale first (no scaling)
	Model = glm::rotate(Model, f, glm::vec3(0, 1, 0));		//then apply rotation

    // Our ModelViewProjection : multiplication of our 3 matrices
    glm::mat4 MVP        = Projection * View * Model; // Remember, matrix multiplication is the other way around

	glUseProgram(_p);

	glUniformMatrix4fv(MVPID, 1, GL_FALSE, &MVP[0][0]);
    glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &Model[0][0]);
    glUniformMatrix4fv(ViewMatrixID, 1, GL_FALSE, &View[0][0]);

}

static void RenderSceneCB(GLuint _p, GLuint Texture, GLuint TextureID, int VerticesAmount, GLuint LightID)//render scene is run every frame
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//use the shader program
	glUseProgram(_p);

	glm::vec3 lightPos = glm::vec3(3,0,3);						//set the position of the light
    glUniform3f(LightID, lightPos.x, lightPos.y, lightPos.z);	//apply the light program

    // Bind our texture in Texture Unit 0
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, Texture);
    // Set our "myTextureSampler" sampler to user Texture Unit 0
    glUniform1i(TextureID, 0);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glEnableVertexAttribArray(2);
    glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_TRIANGLES, 0, VerticesAmount);//display the specified GL_TRIANGLES primitives

    glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
}

static int CreateVertexBuffer()//create our checkered cube
{
	// Read our .obj file
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec2> uvs;
    std::vector<glm::vec3> normals;
    bool passed = loadOBJ("cube2.obj", vertices, uvs, normals);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);

    glGenBuffers(1, &uvbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
    glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);

	glGenBuffers(1, &normalbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
	glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), &normals[0], GL_STATIC_DRAW);

	return vertices.size();
}

int main( int argc, char** argv) {

	GLFWwindow* window;

	glfwSetErrorCallback(error_callback);
	if( !glfwInit())													//initilize the GLFW window
		exit(EXIT_FAILURE);

	window = glfwCreateWindow(800, 800, "Shader Triangle", NULL, NULL); //Create the window
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

	glfwMakeContextCurrent(window);										//Set as current window
	glfwSwapInterval(1);

	glfwSetKeyCallback(window, key_callback);

    //Check glew for errors after initilization
    GLenum res = glewInit();
    if (res != GLEW_OK) {
      fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
      return 1;
    }
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	Shader shaderProgram;
	GLuint programID		=	shaderProgram.CompileShader();				//compile the shader program and get the program id for the shader program
	GLuint MatrixID			=	glGetUniformLocation(programID, "MVP");		//MVP matrix handle passed into the shader progam
	GLuint ViewMatrixID		=	glGetUniformLocation(programID, "V");		//View matrix handle passed into the shader program
    GLuint ModelMatrixID	=	glGetUniformLocation(programID, "M");		//Model matrix handle passed into the shader program
	
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);									//set the backround to black

	float RotateAngle = 0.0f;
	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
		glCullFace(GL_FRONT);//backface culling is having the oposite effect due to the order that the verticeies are loaded, so I changed to to "front" face culling
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	GLuint Texture = loadDDS("CheckerPatternPaper.dds");											//load the textures
	GLuint TextureID  = glGetUniformLocation(programID, "myTextureSampler");						//apply textures to the shader program

	int numVertecies	= CreateVertexBuffer();														//create the vertex/uv buffer
	glUseProgram(programID);
	GLuint LightID		=	glGetUniformLocation(programID, "LightPosition_worldspace");			//Light handle passed into the shader program

	glm::mat4 MVP[2];
																				//Vector containing the Model, View, and Projection matri

	while ( !glfwWindowShouldClose(window))															//main loop
	{
		glUseProgram(programID);
		RotateAngle = 0.0002f;													//change the rotation of the cube by 0.0002 degrees per frame
		if(RotateAngle > 360.0f || RotateAngle < -360.0f)
			RotateAngle = 0.0;
		
		CameraMatrix(programID, MatrixID, ViewMatrixID, ModelMatrixID, RotateAngle);
		RenderSceneCB(programID, Texture, TextureID, numVertecies, LightID);						//render the scene using the shader program
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glfwSwapBuffers(window);																	//swap the buffer
		glfwPollEvents();																			//poll for escape character

		
	}
	
	//cleanup for after the program is finished
	glDeleteBuffers(1, &VBO);			//Delete the VBO
	glDeleteBuffers(1, &uvbuffer);		//Delete the uv buffer
	glDeleteBuffers(1, &normalbuffer);	//Delete the normal buffer
	glDeleteProgram(programID);			//Delete the shader program
	glDeleteTextures(1, &Texture);		//Delete the texture

	glfwTerminate();

	return 0;
}
*/