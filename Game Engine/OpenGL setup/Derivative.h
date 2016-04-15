#ifndef DERIVATIVE_H
#define DERIVATIVE_H

#include <glm\glm.hpp>
#include <glm\gtx\quaternion.hpp>
#include <glm\vec3.hpp>
#include <glm\vec4.hpp>

class Derivative
{
public:
	Derivative();
	Derivative(	const glm::vec3& v,
				const glm::vec3& a,
				const glm::vec3& f,
				const glm::quat& s,
				const glm::vec3& t);

	void set_dx(const glm::vec3& v){ dx = v;};
	void set_dv(const glm::vec3& a){ dv = a;};
	void setForce(const glm::vec3& f){ force = f;};

	glm::vec3 get_dx(){return dx;};
	glm::vec3 get_dv(){return dv;};
	glm::vec3 getForce(){return force;};

	glm::quat getSpin(){return spin;};	
	glm::vec3 getTorque(){return torque;};
	void setSpin(const glm::quat& s){spin = s;};
	void setTorque(const glm::vec3& t){ torque = t;};

private:
	//linear
	glm::vec3 dx;
	glm::vec3 dv;
	glm::vec3 force;

	//angular
	glm::quat spin;
	glm::vec3 torque;
};
#endif