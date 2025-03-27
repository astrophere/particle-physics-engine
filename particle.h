#pragma once

#include "vector3d.h"
#include <assert.h>
#include <stdlib.h>


using namespace MPE;

typedef float real;

class Particle
{
protected:
	Vector3D position;

	Vector3D velocity;

	Vector3D acceleration;

	real damping = 0.999999;

	real inverseMass;

	Vector3D forceAccum; //sum of the forces acting of the particle


public:
	Particle(const real x, const real y, const real z) : position(x, y, z) {}

	Particle() : position(0, 0, 0) {}



	void integrate(real duration)
	{
		if (inverseMass <= 0.0f) return;

		assert(duration > 0.0);
		
		//work out acceleration from the force
		Vector3D resultingAcc = acceleration;
		resultingAcc.addScaledVector(forceAccum, inverseMass);


		//update linear velocity from acceleration
		velocity.addScaledVector(resultingAcc, duration);

		//impose drag due to computational precision
		velocity *= pow(damping, duration);

		//update position
		position.addScaledVector(velocity, duration);

		//Clear the forces
		clearAccumulator();
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

	Vector3D getPosition()
	{
		return position;
	}

	Vector3D getVelocity()
	{
		return velocity;
	}

	Vector3D getAcceleration()
	{
		return acceleration;
	}

	void clearAccumulator()
	{
		forceAccum = Vector3D();
	}

	void addForce(const Vector3D &force)
	{
		forceAccum += force;
	}
};


