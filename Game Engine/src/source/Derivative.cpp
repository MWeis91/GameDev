#include "Derivative.h"

Derivative::Derivative()
{
	set_dx(glm::vec3(0, 0, 0));
	set_dv(glm::vec3(0, 0, 0));
	setForce(glm::vec3(0, 0, 0));

	setSpin(glm::quat(1, 0, 0, 0));
	setTorque(glm::vec3(0, 0, 0));
}

Derivative::Derivative(const glm::vec3& v, const glm::vec3& a, const glm::vec3& f, const glm::quat& s, const glm::vec3& t)
{
	set_dx(v);
	set_dv(a);
	setForce(f);

	setSpin(s);
	setTorque(t);
}