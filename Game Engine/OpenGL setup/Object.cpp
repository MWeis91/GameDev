#include "Object.h"

Object::Object()
{
	glm::mat4 zeroMatrix = glm::mat4(0);

	setModel(zeroMatrix);
	updateViewProjection(zeroMatrix, zeroMatrix);
	//radius = 0.0f;
	//center = glm::vec3(0, 0, 0);
	m.modelTransform(zeroMatrix);
}

Object::~Object()
{

}

void Object::setModel(const glm::mat4& mod)
{
	modelMatrix = mod;
	m.modelTransform(mod);
}

void Object::updateViewProjection(const glm::mat4& view, const glm::mat4& proj)
{
	viewMatrix = view;
	projectionMatrix = proj;

	m.updateViewProjection(view, proj);
}

void Object::drawObject(const GLuint& progID, const GLuint& textureID, const GLuint& lightID, const GLuint& MatID, const GLuint& ModelID, const GLuint& ViewID)
{
	m.modelTransform(modelMatrix);	//update the models model matrix before each draw call
	m.draw(progID, textureID, lightID, MatID, ModelID, ViewID);
}

void Object::LoadModel(const Model& _m)
{
	m = _m;
}


