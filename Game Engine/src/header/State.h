#ifndef PHYSICS_STATE_H
#define PHYSICS_STATE_H

#include<glm\glm.hpp>
#include<glm\fwd.hpp>
#include <glm\gtx\quaternion.hpp>
#include<glm\vec3.hpp>
#include<glm\matrix.hpp>
#include<glm\mat4x4.hpp>
#include <glm\gtc\type_ptr.hpp>
#include<glm\gtc\matrix_transform.hpp>

class State
{
public:
	State();
	State(	const glm::quat &o,
			const float &i,
			const glm::vec3 &pos,
			const glm::vec3 &v,
			const float &m);

	void recalculate();
	void calculateCoordinates();

	glm::mat4 getBodyToWord(){return bodyToWorld;};
	glm::mat4 getWorldToBody(){return worldToBody;};

	void setOrientation(const glm::quat& o){Orientation = o;};
	void setAngularMomentum(const glm::vec3& am){angularMomentum = am;};
	void setSpin(const glm::quat& s){Spin = s;};
	void setAngularVelocity(const glm::vec3& av){angularVelocity = av;};

	void setPosition(const glm::vec3& p){position = p;};
	void setMomentum(const glm::vec3& m){momentum = m;};
	void setAcceleration(const glm::vec3& a){acceleration = a;};
	void setVelocity(const glm::vec3& v){velocity = v;};

	void setMass(const float& m);
	void setInertia(const float& i);

	glm::quat getOrientation(){return Orientation;};
	glm::vec3 getAngularMomentum(){return angularMomentum;};
	glm::quat getSpin(){return Spin;};
	glm::vec3 getAngularVelocity(){return angularVelocity;};
	
	glm::vec3 getPosition(){return position;};
	glm::vec3 getMomentum(){return momentum;};
	glm::vec3 getAcceleration(){return acceleration;};
	glm::vec3 getVelocity(){return velocity;};

	float getMass(){return mass;};
	float getInverseMass(){return inverseMass;};
	float getInertia(){return inertia;};
	float getInverseInertia(){return inverseInertia;};

private:
	//Angular motion
	glm::quat Orientation;		//Quaternion
	glm::vec3 angularMomentum;

	glm::quat Spin;				//Quaternion
	glm::vec3 angularVelocity;
	
	float inertia;
	float inverseInertia;
	float inertiaTensor;
	float inverseInertiaTensor;

	//Linear motion
	glm::vec3 position;
	glm::vec3 momentum;
	glm::vec3 acceleration;
	glm::vec3 velocity;
	
	float mass;
	float inverseMass;
	
	float size;

	//body and world coordinates matricies
	glm::mat4 bodyToWorld;
	glm::mat4 worldToBody;
};
#endif