#pragma once

#include "vector3d.h"

#include <assert.h>
#include <stdlib.h>

// TODO: create particle.cpp
// TODO: define Particle = Particle
// TODO: define Particle == Particle

namespace PPE {
	class Particle
	{
	private:
		PPE::Vector3D _position;
		PPE::Vector3D _velocity;
		PPE::Vector3D _acceleration;

		PPE_FLOAT _inverseMass;

	public:
		// Constructors
		// TODO: expand so velocity and acceleration and mass can be set too with a constructor
		Particle(const PPE_FLOAT& x, const PPE_FLOAT& y, const PPE_FLOAT& z)
			: _position(x, y, z), _velocity(0.0f, 0.0f, 0.0f), _acceleration(0.0f, 0.0f, 0.0f), _inverseMass(1.0f) {}
		Particle()
			: _position(0.0f, 0.0f, 0.0f), _velocity(0.0f, 0.0f, 0.0f), _acceleration(0.0f, 0.0f, 0.0f), _inverseMass(1.0f) {}

		// Getters
		PPE::Vector3D getPosition() { return _position;	}
		PPE::Vector3D getVelocity() { return _velocity;	}
		PPE::Vector3D getAcceleration() { return _acceleration;	}
		PPE_FLOAT getMass()
		{
			if(_inverseMass == 0) return 1.0f;
			return 1/_inverseMass;
		}

		// Setters
		void setPosition(const PPE_FLOAT& xx, const PPE_FLOAT& yy, const PPE_FLOAT& zz)
		{
			_position.setX(xx);
			_position.setY(yy);
			_position.setZ(zz);
		}
		void setPosition(const Vector3D& vector)
		{
			_position.setXYZ(vector.getXYZ());
		}

		void setVelocity(const PPE_FLOAT& vx, const PPE_FLOAT& vy, const PPE_FLOAT& vz)
		{
			_velocity.setX(vx);
			_velocity.setY(vy);
			_velocity.setZ(vz);
		}
		void setVelocity(const Vector3D& vector)
		{
			_velocity.setXYZ(vector.getXYZ());
		}

		void setAcceleration(const PPE_FLOAT& ax, const PPE_FLOAT& ay, const PPE_FLOAT& az)
		{
			_acceleration.setX(ax);
			_acceleration.setY(ay);
			_acceleration.setZ(az);
		}
		void setAcceleration(const Vector3D& vector)
		{
			_acceleration.setXYZ(vector.getXYZ());
		}

		template<typename T>
		void setMass(const T mass)
		{
			// TODO: error-proof it from non-numeric types
			PPE_FLOAT floatMass = static_cast<PPE_FLOAT>(mass);
			if (floatMass == 0) return;
			_inverseMass = 1 / floatMass;
		}

		template<typename T>
		void setInverseMass(const T invMass)
		{
			// TODO: error-proof it from non-numeric types
			PPE_FLOAT floatInvMass = static_cast<PPE_FLOAT>(invMass);
			_inverseMass = floatInvMass;
		}

		// Printers
		void printPosition() { _position.print(); }
		void printVelocity() { _velocity.print(); }
		void printAcceleration() { _acceleration.print(); }
		void printMass()
		{
			if (_inverseMass == 0) 
				std::cout << "infinite" << "\n";
			else
				std::cout << 1 / _inverseMass << "\n";
		}
	};
}

