#include "Physics.h"

Physics::Physics()
{

}

Derivative Physics::evaluate(const State& initial, float t)
{
	State s = initial;
	Derivative output;
	output.set_dx(s.getVelocity());
	output.setSpin(s.getSpin());
	output.setTorque(s.getInertia() * s.getAngularVelocity());
	force(s, t, output, s.getAngularMomentum());
	return output;
}

Derivative Physics::evaluate(State &s, float t, float dt, const Derivative &der)
{

	Derivative d = der;
	glm::vec3 deltaAM = s.getAngularMomentum();

	s.setPosition(s.getPosition() + d.get_dx()*dt);
	s.setMomentum(s.getMomentum() + (d.getForce()*dt));
	s.setOrientation(s.getSpin() + (d.getSpin()*dt));
	s.setAngularMomentum(s.getAngularMomentum() + (d.getTorque()*dt));
	deltaAM -= s.getAngularMomentum();
	s.recalculate();

	Derivative output;
	
	output.set_dx(s.getVelocity());
	output.setSpin(s.getSpin());
	force(s, t+dt, output, deltaAM);
	
	return output;
}

glm::vec3 Physics::gravity(const State &s, float dt)
{
	const glm::vec3 gravity = glm::vec3(0.0f, -10.0f, 0.0f);
	return gravity * dt;

}

void Physics::force(State &s, float dt, Derivative &d, glm::vec3& angularMomentum)
{
	d.setForce(d.getForce() + (s.getMass() /** glm::vec3(0, -10.0f, 0)*/));
	if(dt !=0)
	{
		d.setTorque(d.getTorque() + (angularMomentum / dt));
	}
	
}

void Physics::integrate(State &s, float t, float dt)
{
	Derivative a, b, c, d;

	a = evaluate(s, t);
	b = evaluate(s, t, dt*0.5f, a);
	c = evaluate(s, t, dt*0.5f, b);
	d = evaluate(s, t, dt, c);

	glm::vec3 dxdt = 1.0f/6.0f * dt * (a.get_dx() + 2.0f*(b.get_dx() +c.get_dx()) +d.get_dx() );
	glm::vec3 dmdt = 1.0f/6.0f * dt * (a.getForce() + 2.0f*(b.getForce()+c.getForce())+d.getForce());
	glm::quat dodt = 1.0f/6.0f * dt * (a.getSpin() + 2.0f*(b.getSpin()+c.getSpin())+d.getSpin());
	glm::vec3 damdt = 1.0f/6.0f * dt * (a.getTorque() + 2.0f*(b.getTorque()+c.getTorque())+d.getTorque());
	
	s.setPosition(s.getPosition() + dxdt);
	s.setMomentum(s.getMomentum() + dmdt);
	s.setOrientation(s.getOrientation() + dodt);
	s.setAngularMomentum(s.getAngularMomentum() + damdt);

	s.recalculate();
}
