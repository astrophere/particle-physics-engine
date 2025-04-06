#include "..\include\vector3d.h"
#include <math.h>

namespace PPE {
    // ---> Constructors
    Vector3D::Vector3D() : _x(0.0f), _y(0.0f), _z(0.0f) {}
    Vector3D::Vector3D(const PPE_FLOAT& x, const PPE_FLOAT& y, const PPE_FLOAT& z)
        : _x(x), _y(y), _z(z) {}
    Vector3D::Vector3D(const Vector3D& vector) 
    : _x(vector.getX()), _y(vector.getY()), _z(vector.getZ()) {}

    // ---> Getters
    PPE_FLOAT Vector3D::getX() const { return _x; }
    PPE_FLOAT Vector3D::getY() const { return _y; }
    PPE_FLOAT Vector3D::getZ() const { return _z; }
    Vector3D Vector3D::getXYZ() const { return Vector3D(_x, _y, _z); }

    // ---> Setters
    void Vector3D::setX(const PPE_FLOAT& val) { _x = val; }
    void Vector3D::setY(const PPE_FLOAT& val) { _y = val; }
    void Vector3D::setZ(const PPE_FLOAT& val) { _z = val; }
    void Vector3D::setXYZ(const PPE_FLOAT& x, const PPE_FLOAT& y, const PPE_FLOAT& z)
    {
        _x = x;
        _y = y;
        _z = z;
    }
    void Vector3D::setXYZ(const Vector3D& vector)
    {
        _x = vector.getX();
        _y = vector.getY();
        _z = vector.getZ();
    }

    // ---> Core functionality
    void Vector3D::invert()
    {
        _x = -_x;
        _y = -_y;
        _z = -_z;
    }

    PPE_FLOAT Vector3D::magnitude() const
    {
        return sqrt(_x * _x + _y * _y + _z * _z);
    }

    PPE_FLOAT Vector3D::squareMagnitude() const
    {
        return _x * _x + _y * _y + _z * _z;
    }

    void Vector3D::normalise()
    {
        PPE_FLOAT len = magnitude();
        if (len > 0)
        {
            _x /= len;
            _y /= len;
            _z /= len;
        }
    }

    void Vector3D::clear()
    {
        _x = _y = _z = 0.0f;
    }

    // ---> Operators
    // Assign one vector to be equal to another vector
    // a = b
    Vector3D& Vector3D::operator=(const Vector3D& vector)
    {
        if (this == &vector) return *this;  // protect against self-assignment

        _x = vector.getX();
        _y = vector.getY();
        _z = vector.getZ();

        return *this;
    }

    // Multiply scalar * vector & vector * scalar
    // a *= scalar (a = a * scalar)
    void Vector3D::operator*=(const PPE_FLOAT& scalar)
    {
        _x *= scalar;
        _y *= scalar;
        _z *= scalar;
    }
    // c = a * scalar
    Vector3D Vector3D::operator*(const PPE_FLOAT& scalar)
    {
        return Vector3D(_x * scalar, _y * scalar, _z * scalar);
    }

    // Sum Vector + Vector
    // a += b (a = a + b)
    // TODO: v._x instead of v.getX() ???
    void Vector3D::operator+=(const Vector3D& v)
    {
        _x += v.getX();
        _y += v.getY();
        _z += v.getZ();
    }
    // c = a + b
    Vector3D Vector3D::operator+(const Vector3D& v)
    {
        return Vector3D(_x + v.getX(), _y + v.getY(), _z + v.getZ());
    }

    // Subtract Vector - Vector
    // a -= b (a = a - b)
    void Vector3D::operator-=(const Vector3D& v)
    {
        _x -= v.getX();
        _y -= v.getY();
        _z -= v.getZ();
    }
    // c = a - b
    Vector3D Vector3D::operator-(const Vector3D& v)
    {
        return Vector3D(_x - v.getX(), _y - v.getY(), _z - v.getZ());
    }

    // v %= w (v % w)
    void Vector3D::operator%=(const Vector3D& v)
    {
        *this = vectorProduct(v);
    }
    // Vector % Vector (vector product)
    Vector3D Vector3D::operator%(const Vector3D& v)
    {
        return Vector3D(_y * v.getZ() - _z * v.getY(), _z * v.getX() - _x * v.getZ(), _x * v.getY() - _y * v.getX());
    }

    // ---> Maths for vectors
    // Add scaled vector
    void Vector3D::addScaledVector(const Vector3D& v, const PPE_FLOAT& scalar)
    {
        _x += scalar * v.getX();
        _y += scalar * v.getY();
        _z += scalar * v.getZ();
    }

    // Component-wise multiplication
    void Vector3D::componentProductUpdate(const Vector3D& v)
    {
        _x *= v.getX();
        _y *= v.getY();
        _z *= v.getZ();
    }
    Vector3D Vector3D::componentProduct(const Vector3D& v)
    {
        return Vector3D(_x * v.getX(), _y * v.getY(), _z * v.getZ());
    }

    // Scalar product
    PPE_FLOAT Vector3D::scalarProduct(const Vector3D& v)
    {
        return _x * v.getX() + _y * v.getY() + _z * v.getZ();
    }
    // Vector * Vector (scalar product)
    PPE_FLOAT Vector3D::operator*(const Vector3D& v) const
    {
        return _x * v.getX() + _y * v.getY() + _z * v.getZ();
    }

    // Vector product
    Vector3D Vector3D::vectorProduct(const Vector3D& v)
    {
        return Vector3D(_y * v.getZ() - _z * v.getY(), _z * v.getX() - _x * v.getZ(), _x * v.getY() - _y * v.getX());
    }

    // ---> Utility
    void Vector3D::print()
    {
        std::cout << _x << " " << _y << " " << _z << "\n";
    }


}