#include "Window.h"

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)//polls for escape character
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

Window::Window()
{

}

Window::Window(const int &h, const int &w)
{
	initilize(h, w, "Title");
}

Window::Window(const int &h, const int &w, const char* title)
{
	initilize(h, w, title);
}

Window::~Window()
{
	glfwTerminate();
}

void Window::initilize(const int &h, const int &w, const char* title)
{
	glfwSetErrorCallback(error_callback);
	if( !glfwInit())													//initilize the GLFW window
		exit(EXIT_FAILURE);

	window = glfwCreateWindow(w, h, title, NULL, NULL); //Create the window
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

}

void Window::activateWindow()
{
	glfwMakeContextCurrent(window);										//Set as current window
	glfwSwapInterval(1);

	glfwSetKeyCallback(window, key_callback);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
}

void Window::updateWindow()
{
	glfwSwapBuffers(window);				//swap the buffer
	glfwPollEvents();
}

bool Window::checkClose()
{
	if( !glfwWindowShouldClose(window) )
		return true;
	else
		return false;
}

