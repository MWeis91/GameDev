#include "Render.h"

Render::Render()
{
	programID = 0;
	MatrixID = 0;
	ViewMatrixID = 0;
	ModelMatrixID = 0;
	TextureID = 0;
	LightID = 0;
}

void Render::Initilize(const int &h, const int &w, const char* t)
{
	window.initilize(w, h, t);
	window.activateWindow();

	GLenum res = glewInit();										//goes in initilization of rendering engine
    if (res != GLEW_OK) {
      fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
      exit(1);
    }

	Shader shaderProgram;
	programID		=	shaderProgram.CompileShader();				//compile the shader program and get the program id for the shader program
	MatrixID		=	glGetUniformLocation(programID, "MVP");		//MVP matrix handle passed into the shader progam
	ViewMatrixID	=	glGetUniformLocation(programID, "V");		//View matrix handle passed into the shader program
    ModelMatrixID	=	glGetUniformLocation(programID, "M");		//Model matrix handle passed into the shader program
	TextureID		=	glGetUniformLocation(programID, "myTextureSampler");						//apply textures to the shader program
	LightID			=	glGetUniformLocation(programID, "LightPosition_worldspace");			//Light handle passed into the shader program

	glClearColor(0.20f, 0.20f, 0.20f, 0.20f);									//set the backround to black

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
		glCullFace(GL_FRONT);//backface culling is having the oposite effect due to the order that the verticeies are loaded, so I changed to to "front" face culling
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	glUseProgram(programID);
	
}

bool Render::pollExit()
{
	return window.checkClose();
}
void Render::update()
{
	glUseProgram(programID);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Render::updateWindow()
{
	window.updateWindow();
}

void Render::drawModel( Model &_m)
{
	_m.draw(getProgID(), getTextureID(), getLightID(), getMVPID(), getModelID(), getViewID());
}

void Render::end()
{
	glDeleteProgram(programID);			//Delete the shader program
}
