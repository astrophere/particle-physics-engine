#pragma once

#include "vector3d.h"

#include <assert.h>
#include <stdlib.h>



class Particle
{
private:
	PPE::Vector3D _position = Vector3D();
	PPE::Vector3D _velocity = Vector3D();
	PPE::Vector3D _acceleration = Vector3D();

	PPE_FLOAT _inverseMass;

	PPE::Vector3D _force; // _forces acting on the particle

	//PPE_FLOAT damping = 0.999999;


public:
	Particle(const PPE_FLOAT x, const PPE_FLOAT y, const PPE_FLOAT z) : _position(x, y, z) {}

	Particle() : _position(0, 0, 0) {}

	void setMass(const PPE_FLOAT mass)
	{
		if (mass == 0) return;
		_inverseMass = 1 / mass;
	}

	PPE_FLOAT getMass()
	{
		if(_inverseMass == 0) return;
		return 1/_inverseMass;
	}
	
	void setInverseMass(const PPE_FLOAT invMass)
	{
		_inverseMass = invMass;
	}

	void printPosition()
	{
		_position.print();
	}

	void printVelocity()
	{
		_velocity.print();
	}

	void printAcceleration()
	{
		_acceleration.print();
	}

	void printMass()
	{
		if (_inverseMass == 0) 
			std::cout << "infinite" << "\n";
		else
			std::cout << 1 / _inverseMass << "\n";
	}

	void setInitialPosition(const PPE_FLOAT xx, const PPE_FLOAT yy, const PPE_FLOAT zz)
	{
		_position.setX(xx);
		_position.setY(yy);
		_position.setZ(zz);
	}

	void setInitialVelocity(const PPE_FLOAT vx, const PPE_FLOAT vy, const PPE_FLOAT vz)
	{
		_velocity.setX(vx);
		_velocity.setY(vy);
		_velocity.setZ(vz);
	}

	void setAcceleration(const PPE_FLOAT ax, const PPE_FLOAT ay, const PPE_FLOAT az)
	{
		_acceleration.setX(ax);
		_acceleration.setY(ay);
		_acceleration.setZ(az);
	}

	PPE::Vector3D getPosition()
	{
		return _position;
	}

	PPE::Vector3D getVelocity()
	{
		return _velocity;
	}

	PPE::Vector3D getAcceleration()
	{
		return _acceleration;
	}

	void clearAccumulator()
	{
		_force = PPE::Vector3D();
	}

	void addForce(const PPE::Vector3D &_f)
	{
		_force += _f;
	}
};


