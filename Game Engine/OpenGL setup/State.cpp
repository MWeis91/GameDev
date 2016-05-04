#include "State.h"

void normalize(glm::quat& quant)
{
	const float length = quant.length();
	if(length == 0)
	{
		quant = glm::quat(1.0f, 0.0f, 0.0f, 0.0f);
	}
	else
	{
		float inv = 1.0f / length;
		quant.w = quant.w * inv;
		quant.x = quant.x * inv;
		quant.y = quant.y * inv;
		quant.z = quant.z * inv;
	}
}

State::State()
{
	Orientation = glm::quat(0.0f, 0.0f, 0.0f, 0.0f);
	angularMomentum = glm::vec3(0.0f, 0.0f, 0.0f);
	setInertia(1.0f);

	position = glm::vec3(0.0f, 0.0f, 0.0f);
	velocity = glm::vec3(0.0f, 0.0f, 0.0f);
	setMass(1.0f);
	momentum = mass * velocity;
}

State::State(	const glm::quat &o, const float &i, const glm::vec3 &pos, const glm::vec3 &v, const float &m)
{
	Orientation = o;
	setInertia(i);
	angularMomentum = inertia * glm::vec3(Orientation.x, Orientation.y, Orientation.z);
	
	position = pos;
	velocity = v;
	setMass(m);
	momentum = mass * velocity;
}

void State::recalculate()
{
	//recalculate the linear velocity
	velocity = momentum * inverseMass;

	//recalculate the angular velocity
	angularVelocity = angularMomentum * inverseInertia;

	//normalize( Orientation );
	glm::normalize(Orientation);
	glm::quat q = glm::quat(1.0f, angularVelocity.x, angularVelocity.y, angularVelocity.z);
	Spin = 0.5f * q * Orientation;

	calculateCoordinates();
}

void State::calculateCoordinates()
{
	glm::mat4 translation = glm::translate(glm::mat4(1.0), position);
	glm::quat orientationQuat = glm::quat(Orientation.w, Orientation.x, Orientation.y, Orientation.z);
	glm::mat4 rotationMat = glm::mat4_cast(orientationQuat);

	bodyToWorld = translation * rotationMat;
	worldToBody = glm::inverse(bodyToWorld);
	
}

void State::setMass(const float& m)
{
	mass = m;
	inverseMass = (1.0f/mass);
}

void State::setInertia(const float& i)
{
	inertia = i;
	inverseInertia = (1.0f / inertia);
	inertiaTensor = mass* size *size * 1.0f/6.0f;
	inverseInertiaTensor = 1 / inertiaTensor;
}