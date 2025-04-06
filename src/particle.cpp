#pragma once

#include "particle.h"

#include <assert.h>
#include <stdlib.h>

namespace PPE {
    // --> Constructors
    Particle::Particle(const PPE_FLOAT& x, const PPE_FLOAT& y, const PPE_FLOAT& z)
        : _position(x, y, z), _velocity(0.0f, 0.0f, 0.0f), _acceleration(0.0f, 0.0f, 0.0f), _inverseMass(1.0f) {}
    Particle::Particle()
        : _position(0.0f, 0.0f, 0.0f), _velocity(0.0f, 0.0f, 0.0f), _acceleration(0.0f, 0.0f, 0.0f), _inverseMass(1.0f) {}

    // --> Getters
    PPE::Vector3D Particle::getPosition() { return _position;	}
    PPE::Vector3D Particle::getVelocity() { return _velocity;	}
    PPE::Vector3D Particle::getAcceleration() { return _acceleration;	}
    PPE_FLOAT Particle::getMass()
    {
        if(_inverseMass == 0) return 1.0f;
        return 1/_inverseMass;
    }

    // --> Setters
    void Particle::setPosition(const PPE_FLOAT& xx, const PPE_FLOAT& yy, const PPE_FLOAT& zz)
    {
        _position.setX(xx);
        _position.setY(yy);
        _position.setZ(zz);
    }
    void Particle::setPosition(const Vector3D& vector)
    {
        _position.setXYZ(vector.getXYZ());
    }

    void Particle::setVelocity(const PPE_FLOAT& vx, const PPE_FLOAT& vy, const PPE_FLOAT& vz)
    {
        _velocity.setX(vx);
        _velocity.setY(vy);
        _velocity.setZ(vz);
    }
    void Particle::setVelocity(const Vector3D& vector)
    {
        _velocity.setXYZ(vector.getXYZ());
    }

    void Particle::setAcceleration(const PPE_FLOAT& ax, const PPE_FLOAT& ay, const PPE_FLOAT& az)
    {
        _acceleration.setX(ax);
        _acceleration.setY(ay);
        _acceleration.setZ(az);
    }
    void Particle::setAcceleration(const Vector3D& vector)
    {
        _acceleration.setXYZ(vector.getXYZ());
    }

    template<typename T>
    void Particle::setMass(const T mass)
    {
        // TODO: error-proof it from non-numeric types
        PPE_FLOAT floatMass = static_cast<PPE_FLOAT>(mass);
        if (floatMass == 0) return;
        _inverseMass = 1 / floatMass;
    }

    template<typename T>
    void Particle::setInverseMass(const T invMass)
    {
        // TODO: error-proof it from non-numeric types
        PPE_FLOAT floatInvMass = static_cast<PPE_FLOAT>(invMass);
        _inverseMass = floatInvMass;
    }

    // --> Printers
    void Particle::printPosition() { _position.print(); }
    void Particle::printVelocity() { _velocity.print(); }
    void Particle::printAcceleration() { _acceleration.print(); }
    void Particle::printMass()
    {
        if (_inverseMass == 0) 
            std::cout << "infinite" << "\n";
        else
            std::cout << 1 / _inverseMass << "\n";
    }
};