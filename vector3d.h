#pragma once

#include "types.h"

#include <iostream>
#include <math.h>



namespace MPE {
	class Vector3D
	{
	private:
		MPE_FLOAT _x, _y, _z;
		MPE_FLOAT _pad; //padding for storing 4 values in the memory cause it be better

	public:
		// Default constructor
		Vector3D() : _x(0), _y(0), _z(0)
		{}

		// Explicit constructor
		Vector3D(const MPE_FLOAT x, const MPE_FLOAT y, const MPE_FLOAT z)
			: _x(x), _y(y), _z(z) {}

		// Getters
		MPE_FLOAT getX() const { return _x; }
		MPE_FLOAT getY() const { return _y; }
		MPE_FLOAT getZ() const { return _z; }
	
		// Setters
		void setX(MPE_FLOAT val) { _x = val; }
		void setY(MPE_FLOAT val) { _y = val; }
		void setZ(MPE_FLOAT val) { _z = val; }

		void invert()
		{
			_x = -_x;
			_y = -_y;
			_z = -_z;
		}

		MPE_FLOAT magnitude() const
		{
			return sqrt(_x * _x + _y * _y + _z * _z);
		}

		MPE_FLOAT squareMagnitude() const
		{
			return _x * _x + _y * _y + _z * _z;
		}

		void normalise()
		{
			MPE_FLOAT len = magnitude();
			if (len > 0)
			{
				_x /= len;
				_y /= len;
				_z /= len;
			}
		}

		// Multiply scalar * vector & vector * scalar
		// a *= scalar (a = a * scalar)
		void operator*=(const MPE_FLOAT scalar)
		{
			_x *= scalar;
			_y *= scalar;
			_z *= scalar;
		}
		// c = a * scalar
		Vector3D operator*(const MPE_FLOAT scalar)
		{
			return Vector3D(_x * scalar, _y * scalar, _z * scalar);
		}

		// Sum Vector + Vector
		// a += b (a = a + b)
		void operator+=(const Vector3D& v)
		{
			_x += v.getX();
			_y += v.getY();
			_z += v.getZ();
		}
		// c = a + b
		Vector3D operator+(const Vector3D& v)
		{
			return Vector3D(_x + v.getX(), _y + v.getY(), _z + v.getZ());
		}

		// Subtract Vector - Vector
		// a -= b (a = a - b)
		void operator-=(const Vector3D& v)
		{
			_x -= v.getX();
			_y -= v.getY();
			_z -= v.getZ();
		}
		// c = a - b
		Vector3D operator-(const Vector3D& v)
		{
			return Vector3D(_x - v.getX(), _y - v.getY(), _z - v.getZ());
		}

		// Add scaled vector
		void addScaledVector(const Vector3D v, const MPE_FLOAT scalar)
		{
			_x += scalar * v.getX();
			_y += scalar * v.getY();
			_z += scalar * v.getZ();
		}

		// Component-wise multiplication
		void componentProductUpdate(const Vector3D& v)
		{
			_x *= v.getX();
			_y *= v.getY();
			_z *= v.getZ();
		}
		Vector3D componentProduct(const Vector3D& v)
		{
			return Vector3D(_x * v.getX(), _y * v.getY(), _z * v.getZ());
		}

		// Scalar product
		MPE_FLOAT scalarProduct(const Vector3D& v)
		{
			return _x * v.getX() + _y * v.getY() + _z * v.getZ();
		}
		// Vector * Vector (scalar product)
		MPE_FLOAT operator*(const Vector3D& v) const
		{
			return _x * v.getX() + _y * v.getY() + _z * v.getZ();
		}

		// Vector product
		Vector3D vectorProduct(const Vector3D& v)
		{
			return Vector3D(_y * v.getZ() - _z * v.getY(), _z * v.getX() - _x * v.getZ(), _x * v.getY() - _y * v.getX());
		}
		// v %= w (v % w)
		void operator%=(const Vector3D& v)
		{
			*this = vectorProduct(v);
		}
		// Vector % Vector (vector product)
		Vector3D operator%(const Vector3D& v)
		{
			return Vector3D(_y * v.getZ() - _z * v.getY(), _z * v.getX() - _x * v.getZ(), _x * v.getY() - _y * v.getX());
		}

		// Print vector
		void print()
		{
			std::cout << _x << " " << _y << " " << _z << "\n";
		}

		void clear()
		{
			_x = _y = _z = 0;
		}
	};

}
