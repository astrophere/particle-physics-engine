#pragma once

#include <iostream>
#include <math.h>



namespace beepbop {
	class Vector3D
	{
	public:
		typedef float real;

		real x; //the x, y, z coordinates of the vector
		real y;
		real z;

		//the default constructor creates a zero vector
		Vector3D() : x(0), y(0), z(0)
		{}

		//the explicit constructor creates a vecotr with 3 given values as coordinates
		Vector3D(const real x, const real y, const real z)
			: x(x), y(y), z(z) {}

		//flips all the components of the vector
		void invert()
		{
			x = -x;
			y = -y;
			z = -z;
		}

		real magnitude() const
		{
			return sqrt(x * x + y * y + z * z);
		}

		real squareMagnitude() const
		{
			return x * x + y * y + z * z;
		}

		void normalise()
		{
			real len = magnitude();
			if (len > 0)
			{
				x /= len;
				y /= len;
				z /= len;
			}
		}

		//overloading the * operator to multipy 3d vectors by scalars
		void operator*=(const real value)
		{
			x *= value;
			y *= value;
			z *= value;
		}

		//returning the copy of a vector multipied by a scalar
		Vector3D operator*(const real value) const
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
		void addScaledVector(const Vector3D& vector, const real scalar)
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
		real scalarProduct(const Vector3D& v)
		{
			return x * v.x + y * v.y + z * v.z;
		}

		//overloading multiplication of two Vector3D so it returns a scalar product
		real operator*(const Vector3D& v) const
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

	private:
		real pad; //padding for storing 4 values in the memory cause it be better

	};

}
