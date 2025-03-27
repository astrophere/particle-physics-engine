#pragma once

#include "vector3d.h"

#include <assert.h>
#include <stdlib.h>



class Particle
{
private:
	MPE::Vector3D position;

	MPE::Vector3D velocity;

	MPE::Vector3D acceleration;

	MPE_FLOAT damping = 0.999999;

	MPE_FLOAT inverseMass;

	MPE::Vector3D forceAccum; //sum of the forces acting of the particle


public:
	Particle(const MPE_FLOAT x, const MPE_FLOAT y, const MPE_FLOAT z) : position(x, y, z) {}

	Particle() : position(0, 0, 0) {}



	void integrate(MPE_FLOAT duration)
	{
		if (inverseMass <= 0.0f) return;

		assert(duration > 0.0);
		
		//work out acceleration from the force
		MPE::Vector3D resultingAcc = acceleration;
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



	void setMass(const MPE_FLOAT mass)
	{
		if (mass == 0) return;
		inverseMass = 1 / mass;
	}
	
	void setInverseMass(const MPE_FLOAT invMass)
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

	void setInitialPosition(const MPE_FLOAT xx, const MPE_FLOAT yy, const MPE_FLOAT zz)
	{
		position.setX(xx);
		position.setY(yy);
		position.setZ(zz);
	}

	void setInitialVelocity(const MPE_FLOAT vx, const MPE_FLOAT vy, const MPE_FLOAT vz)
	{
		velocity.setX(vx);
		velocity.setY(vy);
		velocity.setZ(vz);
	}

	void setAcceleration(const MPE_FLOAT ax, const MPE_FLOAT ay, const MPE_FLOAT az)
	{
		acceleration.setX(ax);
		acceleration.setY(ay);
		acceleration.setZ(az);
	}

	MPE::Vector3D getPosition()
	{
		return position;
	}

	MPE::Vector3D getVelocity()
	{
		return velocity;
	}

	MPE::Vector3D getAcceleration()
	{
		return acceleration;
	}

	void clearAccumulator()
	{
		forceAccum = MPE::Vector3D();
	}

	void addForce(const MPE::Vector3D &force)
	{
		forceAccum += force;
	}
};


