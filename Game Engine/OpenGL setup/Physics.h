#ifndef PHY_H
#define PHY_H

#include<glm\glm.hpp>
#include<glm\fwd.hpp>
#include<glm\vec3.hpp>
#include<glm\gtc\matrix_transform.hpp>


class Physics
{

public:
	Physics();

	struct Derivative
	{
		glm::vec3 dx;	//velocity
		glm::vec3 dv;	//acceleration
	};

	struct State
	{
		glm::vec3 position;
		glm::vec3 velocity;
	
	};

	Derivative evaluate( const State &initial, float t, float dt, const Derivative &d);
	glm::vec3 acceleration(const State &state, float t);
	void integrate(State &s, float t, float dt);


};
#endif





