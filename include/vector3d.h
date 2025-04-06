#pragma once

#include "types.h"
#include <iostream>

namespace PPE {
	class Vector3D
	{
	private:
		PPE_FLOAT _x, _y, _z;

	public:
		// Constructors
		Vector3D();
		Vector3D(const PPE_FLOAT& x, const PPE_FLOAT& y, const PPE_FLOAT& z);
		Vector3D(const Vector3D& vector);

		// Getters
		PPE_FLOAT getX() const;
		PPE_FLOAT getY() const;
		PPE_FLOAT getZ() const;
		Vector3D getXYZ() const;
	
		// Setters
		void setX(const PPE_FLOAT& val);
		void setY(const PPE_FLOAT& val);
		void setZ(const PPE_FLOAT& val);
		void setXYZ(const PPE_FLOAT& x, const PPE_FLOAT& y, const PPE_FLOAT& z);
		void setXYZ(const Vector3D& vector);

		// Core functionality
		void invert();
		PPE_FLOAT magnitude() const;
		PPE_FLOAT squareMagnitude() const;
		void normalise();
		void clear();

		// Operators
		Vector3D& operator=(const Vector3D& vector);
		void operator*=(const PPE_FLOAT& scalar);
		Vector3D operator*(const PPE_FLOAT& scalar);
		void operator+=(const Vector3D& v);
		Vector3D operator+(const Vector3D& v);
		void operator-=(const Vector3D& v);
		Vector3D operator-(const Vector3D& v);
		PPE_FLOAT operator*(const Vector3D& v) const;
		void operator%=(const Vector3D& v);
		Vector3D operator%(const Vector3D& v);

		// Maths for vectors
		void addScaledVector(const Vector3D& v, const PPE_FLOAT& scalar);
		void componentProductUpdate(const Vector3D& v);
		Vector3D componentProduct(const Vector3D& v);
		PPE_FLOAT scalarProduct(const Vector3D& v);
		Vector3D vectorProduct(const Vector3D& v);

		// Utility
		void print();
	};

}
