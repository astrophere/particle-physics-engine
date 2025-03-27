#pragma once

#include "types.h"

#include <iostream>
#include <math.h>



namespace MPE {
	class Vector3D
	{
	private:
		MPE_FLOAT x, y, z;

	public:
		//the default constructor creates a zero vector
		Vector3D() : x(0), y(0), z(0)
		{}

		//the explicit constructor creates a vecotr with 3 given values as coordinates
		Vector3D(const MPE_FLOAT x, const MPE_FLOAT y, const MPE_FLOAT z)
			: x(x), y(y), z(z) {}

		//flips all the components of the vector
		void invert()
		{
			x = -x;
			y = -y;
			z = -z;
		}

		MPE_FLOAT magnitude() const
		{
			return sqrt(x * x + y * y + z * z);
		}

		MPE_FLOAT squareMagnitude() const
		{
			return x * x + y * y + z * z;
		}

		void normalise()
		{
			MPE_FLOAT len = magnitude();
			if (len > 0)
			{
				x /= len;
				y /= len;
				z /= len;
			}
		}

		//overloading the * operator to multipy 3d vectors by scalars
		void operator*=(const MPE_FLOAT value)
		{
			x *= value;
			y *= value;
			z *= value;
		}

		//returning the copy of a vector multipied by a scalar
		Vector3D operator*(const MPE_FLOAT value) const
		{
			return Vector3D(x * value, y * value, z * value);
		}

		//overloading the + operator to add vectors
		void operator+=(const Vector3D& v)
		{
			x += v.x;
			y += v.y;
			z += v.z;
		}

		//returning the vector that is the sum of two vectors
		Vector3D operator+(const Vector3D& v)
		{
			return Vector3D(x + v.x, y + v.y, z + v.z);
		}

		//overloading the subtraction operator, same as addition
		void operator-=(const Vector3D& v)
		{
			x -= v.x;
			y -= v.y;
			z -= v.z;
		}

		Vector3D operator-(const Vector3D& v)
		{
			return Vector3D(x - v.x, y - v.y, z - v.z);
		}

		//a function to add a scaled vector to a given vector
		void addScaledVector(const Vector3D vector, const MPE_FLOAT scalar)
		{
			x += scalar * vector.x;
			y += scalar * vector.y;
			z += scalar * vector.z;
		}

		//a component product - multiplying each component by each other
		void componentProductUpdate(const Vector3D& vector)
		{
			x *= vector.x;
			y *= vector.y;
			z *= vector.z;
		}

		Vector3D componentProduct(const Vector3D& vector)
		{
			return Vector3D(x * vector.x, y * vector.y, z * vector.z);
		}

		// defining the scalar product
		MPE_FLOAT scalarProduct(const Vector3D& v)
		{
			return x * v.x + y * v.y + z * v.z;
		}

		//overloading multiplication of two Vector3D so it returns a scalar product
		MPE_FLOAT operator*(const Vector3D& v) const
		{
			return x * v.x + y * v.y + z * v.z;
		}

		//defining the vector product
		Vector3D vectorProduct(const Vector3D& v)
		{
			return Vector3D(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
		}

		void operator%=(const Vector3D& v)
		{
			*this = vectorProduct(v);
		}

		Vector3D operator%(const Vector3D& v)
		{
			return Vector3D(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
		}

		void print()
		{
			std::cout << x << " " << y << " " << z << "\n";
		}

		void clear()
		{
			x = y = z = 0;
		}

	private:
		MPE_FLOAT pad; //padding for storing 4 values in the memory cause it be better

	};

}
