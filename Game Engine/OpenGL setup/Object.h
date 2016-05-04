#ifndef OBJECT_H
#define OBJECT_H

#include<cstring>
#include<vector>

#include"Model.h"
#include "Physics.h"

#include <GLFW\glfw3.h>
//OpenGL Mathematics
#include<glm\glm.hpp>
#include<glm\fwd.hpp>
#include<glm\vec3.hpp>
#include<glm\gtc\matrix_transform.hpp>

/**************************************************************************************
	Object class
	Params:
		Contains transform(translation/rotation/scale) data for the object
		Hit box dimensions and relativity to the object.
		Model information for rendering the object.
***************************************************************************************/

class Object
{

public:
	Object();
	~Object();

	void LoadModel(	const Model &m );						//load a model into the ModelList
	Model& getModel(){return m;};

	void setModel( const glm::mat4& mod);					//pass and update the model matrix
	void updateViewProjection(	const glm::mat4& view,		//pass and update the view and projection matrix
								const glm::mat4& proj);
	void drawObject(const GLuint& progID,					//Draw the models in the object
					const GLuint& textureID, 
					const GLuint& lightID, 
					const GLuint& MatID, 
					const GLuint& ModelID,
					const GLuint& ViewID);			

	//void rotate(const glm::vec3 &quant, const float& w);	//rotate the object using a derived quaternion rotation matrix
	//void translate(const glm::vec3 &move);					//translate/bounding sphere the object on the xyz axis
	//void scale(const glm::vec3 &scale);						//scale the object along the xyz axis

	//void minimumBoundingSphere();							//construct a minimum bounding sphere for the object(WIP)

			

	//bool collisionCheck(const Object &o);					//check for a collison between another object

	//glm::vec3 getCenter();									//return the center of the bounding sphere
	//float getRadius();										//return the radius of the bounding sphere
	glm::mat4 getModelMat(){return modelMatrix;};
	glm::mat4 getviewMat(){return viewMatrix;};
	glm::mat4 getProjMat(){return projectionMatrix;};

	void update(float dt);											//run the associated script for the object

private:
	//glm::vec3 center;						//xyz position of the center of the bounding sphere
	//float radius;							//radius of the bounding sphere

	glm::mat4 modelMatrix;					//Model matrix for position of our object
	glm::mat4 viewMatrix;					//view matrix for the camera
	glm::mat4 projectionMatrix;				//projection matrix for flattening

	Model m;
};

#endif