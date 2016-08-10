#include "DynamicObject.h"

DynamicObject::DynamicObject()
{
	State curr, prev, interp;
	setCurrentState(curr);
	setPreviousState(prev);
	setInterpolationState(interp);
}

DynamicObject::DynamicObject(const State& curr, const State& prev, const State& interp)
{
	setCurrentState(curr);
	setPreviousState(prev);
	setInterpolationState(interp);
}

void DynamicObject::update(float t, float dt)
{
	setPreviousState(current);
	Physics::integrate(current, t, dt);
}

void DynamicObject::render( float alpha)
{
	interpolate(alpha);
	interpolated.calculateCoordinates();
	setModel(interpolated.getBodyToWord());
}
void DynamicObject::interpolate(float alpha)
{
	interpolated.setPosition(current.getPosition()*alpha + previous.getPosition()*(1-alpha));
	interpolated.setMomentum(current.getMomentum()*alpha + previous.getMomentum()*(1-alpha));

	glm::quat interp = glm::slerp(current.getOrientation(), previous.getOrientation(), alpha);

	interpolated.setOrientation(interp);
	interpolated.setAngularMomentum(current.getAngularMomentum()*alpha + previous.getAngularMomentum()*(1-alpha));
	interpolated.recalculate();

}

void DynamicObject::setCurrentState(const State& c)
{
	current = c;
}

void DynamicObject::setPreviousState(const State& p)
{
	previous = p;
}

void DynamicObject::setInterpolationState(const State& i)
{
	interpolated = i;
}

State DynamicObject::getCurrentState()
{
	return current;
}

State DynamicObject::getPreviousState()
{
	return previous;
}

State DynamicObject::getInterpolatedState()
{
	return interpolated;
}