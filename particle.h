#pragma once


#include "C:\Users\melan\source\repos\beepbopengine\core.h"
#include <assert.h>

typedef float real;

class Particle
{
protected:
	beepbop::Vector3D position;

	beepbop::Vector3D velocity;

	beepbop::Vector3D acceleration;

	real damping = 0.999;

	real inverseMass;

public:
	Particle(const real x, const real y, const real z) : position(x, y, z) {}

	Particle() : position(0, 0, 0) {}



	void integrate(real duration)
	{
		if (inverseMass <= 0.0f) return;

		assert(duration > 0.0);

		//update linear position
		position.addScaledVector(velocity, duration);

		//work out acceleration from the force
		//will be updated later on
		beepbop::Vector3D resultingAcc = acceleration;

		//update linear velocity from acceleration
		velocity.addScaledVector(resultingAcc, duration);

		//impose drag
		velocity *= pow(damping, duration);

		//Clear the forces
		//clearAccumulator();
	}



	void setMass(const real mass)
	{
		if (mass == 0) return;
		inverseMass = 1 / mass;
	}
	
	void setInverseMass(const real invMass)
	{
		inverseMass = invMass;
	}

	void printPosition()
	{
		position.print();
	}

	void printVelocity()
	{
		velocity.print();
	}

	void printAcceleration()
	{
		acceleration.print();
	}

	void printMass()
	{
		if (inverseMass == 0) 
			std::cout << "infinite" << "\n";
		else
			std::cout << 1 / inverseMass << "\n";
	}

	void setInitialPosition(const real xx, const real yy, const real zz)
	{
		position.x = xx;
		position.y = yy;
		position.z = zz;
	}

	void setInitialVelocity(const real vx, const real vy, const real vz)
	{
		velocity.x = vx;
		velocity.y = vy;
		velocity.z = vz;
	}

	void setAcceleration(const real ax, const real ay, const real az)
	{
		acceleration.x = ax;
		acceleration.y = ay;
		acceleration.z = az;
	}

	beepbop::Vector3D getPosition()
	{
		return position;
	}

};


