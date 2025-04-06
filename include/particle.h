#pragma once

#include "types.h"
#include "vector3d.h"

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
		Particle(const PPE_FLOAT& x, const PPE_FLOAT& y, const PPE_FLOAT& z);
		Particle();

		// Getters
		PPE::Vector3D getPosition();
		PPE::Vector3D getVelocity();
		PPE::Vector3D getAcceleration();
		PPE_FLOAT getMass();

		// Setters
		void setPosition(const PPE_FLOAT& xx, const PPE_FLOAT& yy, const PPE_FLOAT& zz);
		void setPosition(const Vector3D& vector);
		void setVelocity(const PPE_FLOAT& vx, const PPE_FLOAT& vy, const PPE_FLOAT& vz);
		void setVelocity(const Vector3D& vector);
		void setAcceleration(const PPE_FLOAT& ax, const PPE_FLOAT& ay, const PPE_FLOAT& az);
		void setAcceleration(const Vector3D& vector);
		template<typename T>
		void setMass(const T mass);
		template<typename T>
		void setInverseMass(const T invMass);

		// Printers
		void printPosition();
		void printVelocity();
		void printAcceleration();
		void printMass();
	};
}

