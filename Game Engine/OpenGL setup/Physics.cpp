#include "Physics.h"

Physics::Physics()
{

}

Physics::Derivative Physics::evaluate(const State &initial, float t, float dt, const Derivative &d)
{
	State s;
	s.position.x = initial.position.x + d.dx.x*dt;
	s.position.y = initial.position.y + d.dx.y*dt;
	s.position.z = initial.position.z + d.dx.z*dt;

	s.velocity.x = initial.velocity.x + d.dv.x*dt;
	s.velocity.y = initial.velocity.y + d.dv.y*dt;
	s.velocity.z = initial.velocity.z + d.dv.z*dt;

	Derivative output;
	output.dx.x = s.velocity.x;
	output.dx.y = s.velocity.y;
	output.dx.z = s.velocity.z;

	output.dv = acceleration(s, t+dt);
	return output;
}

glm::vec3 Physics::acceleration(const State &s, float dt)
{
	const glm::vec3 gravity = glm::vec3(0.0f, 9.8f, 0.0f);

	return gravity * dt;

}

void Physics::integrate(State &s, float t, float dt)
{
	Derivative a, b, c, d;

	a = evaluate(s, t, 0.0f, Derivative() );
	b = evaluate(s, t, dt*0.5f, a);
	c = evaluate(s, t, dt*0.5f, b);
	d = evaluate(s, t, dt, c);

	glm::vec3 dxdt = 1.0f/6.0f* (a.dx + 2.0f*(b.dx +c.dx) +d.dx );

	glm::vec3 dvdt = 1.0f/6.0f* (a.dv + 2.0f*(b.dv +c.dv) +d.dv );

	s.position = s.position + dxdt * dt;
	s.velocity = s.velocity + dvdt * dt;
}