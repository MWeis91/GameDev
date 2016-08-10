#ifndef DYNAMIC_OBJECT_H
#define DYNAMIC_OBJECT_H

#include "Object.h"
#include "State.h"
#include "Physics.h"

class DynamicObject: public Object
{
public:
	DynamicObject();
	DynamicObject(const State& curr, const State& prev, const State& interp);

	void update(float t, float dt);

	void render( float alpha);
	void interpolate(float alpha);

	void updateWorldCoords();
	void updateBodyCoords();

	void setCurrentState(const State& c);
	void setPreviousState(const State& p);
	void setInterpolationState(const State& i);

	State getCurrentState();
	State getPreviousState();
	State getInterpolatedState();

private:
	State current;
	State previous;
	State interpolated;
};
#endif