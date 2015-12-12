#ifndef WINDOW_H
#define WINDOW_H

#include<GLFW\glfw3.h>

#include <string>

class Window
{
public:
	Window();
	Window(	const int &_width,	
			const int &_height);
	Window(	const int &_width, 
			const int &_height, 
			const char* _title);
	~Window();

	void initilize(const int &_width, const int &_height, const char* _title);
	void activateWindow();
	void updateWindow();
	bool checkClose();

	GLFWwindow* getWindow(){return window;}

private:
	GLFWwindow* window;
};
#endif