#ifndef PHY_H
#define PHY_H

#include<glm\glm.hpp>
#include<glm\fwd.hpp>
#include<glm\vec3.hpp>
#include <glm\gtx\quaternion.hpp>
#include<glm\gtc\matrix_transform.hpp>

#include "Derivative.h"
#include "State.h"


class Physics
{

public:
	Physics();

	static Derivative evaluate( State &initial, float t, float dt, const Derivative &d);
	static Derivative evaluate (const State& initial, float t);
	static glm::vec3 gravity(const State &state, float t);
	static glm::vec3 applyForce(const State &s, float t);
	static void force(State& s, float dt, Derivative &d, glm::vec3 &angularMomentum);
	static void integrate(State &s, float t, float dt);

private:
	glm::vec3 g;
	float k;

};
#endif





