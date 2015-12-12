#include "Shader.h"
#include <string>
#include <stdio.h>
#include <iostream>
#include <istream>
#include <fstream>

using namespace std;

Shader::Shader()
{
	CompileShader();
}

string loadFileToString(char const * fname)//used for reading the shader source to a string
{
    ifstream ifile(fname);
    string filetext;

    while( ifile.good() ) {
        string line;
        getline(ifile, line);
        filetext.append(line + "\n");
    }

    return filetext;
}

static void AddShader(GLuint ShaderProgram, const char* pShaderText, GLenum ShaderType)
{
    GLuint ShaderObj = glCreateShader(ShaderType);//create a local copy of ShaderProgram

    if (ShaderObj == 0) {
        fprintf(stderr, "Error creating shader type %d\n", ShaderType);
        exit(0);
    }

    const GLchar* p[1];
    p[0] = pShaderText;//transfer the raw text to a GLchar
    GLint Lengths[1];
    Lengths[0]= strlen(pShaderText);//get the length of the shader
    glShaderSource(ShaderObj, 1, p, Lengths);//specify the source of the shader
    glCompileShader(ShaderObj);//compile the shader
    GLint success;
    glGetShaderiv(ShaderObj, GL_COMPILE_STATUS, &success);
    if (!success) {//check if the shader compiled without error
        GLchar InfoLog[1024];
        glGetShaderInfoLog(ShaderObj, 1024, NULL, InfoLog);
        fprintf(stderr, "Error compiling shader type %d: '%s'\n", ShaderType, InfoLog);
        exit(1);
    }

    glAttachShader(ShaderProgram, ShaderObj);//if the shader compiled correctly, attach the local copy to ShaderProgram
}

GLuint Shader::CompileShader()
{
	GLuint ShaderProgram = glCreateProgram();

    if (ShaderProgram == 0) {
        fprintf(stderr, "Error creating shader program\n");
        exit(1);
    }
    
    string vs, fs;

	vs = loadFileToString("shader.vs");//load the vertex shader to a string
	fs = loadFileToString("shader.fs");//load the fragment shader to a string
	
    AddShader(ShaderProgram, vs.c_str(), GL_VERTEX_SHADER);//compile and attach the vertex shader to ShaderProgram
    AddShader(ShaderProgram, fs.c_str(), GL_FRAGMENT_SHADER);//compile and attach the fragment shader to ShaderProgram

    GLint Success = 0;
    GLchar ErrorLog[1024] = { 0 };

    glLinkProgram(ShaderProgram);//link the ShaderProgram
    glGetProgramiv(ShaderProgram, GL_LINK_STATUS, &Success);//check if the link was a success
	if (Success == 0) {
		glGetProgramInfoLog(ShaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
		fprintf(stderr, "Error linking shader program: '%s'\n", ErrorLog);
        exit(1);
	}

    glValidateProgram(ShaderProgram);//validate the shader program
    glGetProgramiv(ShaderProgram, GL_VALIDATE_STATUS, &Success);//check if the shader program was validated
    if (!Success) {
        glGetProgramInfoLog(ShaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
        fprintf(stderr, "Invalid shader program: '%s'\n", ErrorLog);
        exit(1);
    }

	return ShaderProgram;
}
