#ifndef CAMERA_H
#define CAMERA_H

//GLM matrix and vector operations
#include<glm\glm.hpp>
#include<glm\fwd.hpp>
#include<glm\vec3.hpp>
#include<glm\gtc\matrix_transform.hpp>

class Camera
{
public:
	Camera(const glm::vec3& loc, const glm::vec2& look, const glm::vec3& orient);
	~Camera();

	glm::mat4 getPerspective();
	glm::mat4 getView();

	void setView();
	void setPerspective();
private:
	glm::mat4 perspective;
	glm::mat4 view;

	//View vectors
	glm::vec3 location;
	glm::vec3 lookAt;
	glm::vec3 orientation;

}

#endif