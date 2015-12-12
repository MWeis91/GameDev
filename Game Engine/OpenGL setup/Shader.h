#ifndef SHADERTHING_H
#define SHADERTHING_H

#include <GL\glew.h>

class Shader
{
public:
	Shader();
	GLuint CompileShader();
};
#endif