#include "Object.h"

Object::Object()
{
	glm::mat4 zeroMatrix = glm::mat4(0);

	setModel(zeroMatrix);
	updateViewProjection(zeroMatrix, zeroMatrix);
	radius = 0.0f;
	center = glm::vec3(0, 0, 0);
	m.modelTransform(zeroMatrix);
}

Object::~Object()
{

}

void Object::setModel(const glm::mat4& mod)
{
	modelMatrix = mod;
}

void Object::updateViewProjection(const glm::mat4& view, const glm::mat4& proj)
{
	viewMatrix = view;
	projectionMatrix = proj;

	m.updateViewProjection(view, proj);
}

void Object::rotate(const glm::vec3& quant, const float& w)
{
	//derive the quaternion rotation matrix
}

void Object::translate(const glm::vec3& trans)
{
	modelMatrix = glm::translate(modelMatrix, trans);
}

void Object::scale(const glm::vec3& scale)
{
	modelMatrix = glm::scale(modelMatrix, scale);
}

void Object::drawObject(const GLuint& progID, const GLuint& textureID, const GLuint& lightID, const GLuint& MatID, const GLuint& ModelID, const GLuint& ViewID)
{
	m.modelTransform(modelMatrix);	//update the models model matrix before each draw call
	m.draw(progID, textureID, lightID, MatID, ModelID, ViewID);
}


