#ifndef RENDER_H
#define RENDER_H

#include <GL\glew.h>
#include "Shader.h"
#include "Model.h"
#include "Window.h"

class Render
{
public:
	Render();
	//~Render();

	void Initilize(	const int &_w,		//window width		initilize GLEW and the GLFW window
					const int &_h,		//window height
					const char* _t);	//windown title

	bool pollExit();
	void update();
	void updateWindow();
	void drawModel( Model &_m);	//use the model's matrix info to draw the object
	void end();

	//Shader getShader(){return shaderProgram;}
	GLuint getProgID(){return programID;}	
	GLuint getMVPID(){return MatrixID;}				
	GLuint getViewID(){return ViewMatrixID;}			
	GLuint getModelID(){return ModelMatrixID;}
	GLuint getLightID(){return LightID;}
	GLuint getTextureID(){return TextureID;}
	Window getWindow(){return window;}
	
	void setProgID(const GLuint &_p);
	void setMVPID(const GLuint &_mvp);
	void setViewID(const GLuint &_v);
	void setModelID(const GLuint &_m);
	void setLightID(const GLuint &_l);
	void setTextureID(const GLuint &_t);

private:
	Window window;
	//Shader shaderProgram;
	GLuint programID;				//compile the shader program and get the program id for the shader program
	GLuint MatrixID;				//MVP matrix handle passed into the shader progam
	GLuint ViewMatrixID;			//View matrix handle passed into the shader program
    GLuint ModelMatrixID;			//Model matrix handle passed into the shader program
	GLuint LightID;
	GLuint TextureID;
	
};
#endif