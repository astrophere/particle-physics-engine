#include "integrator.h"

// Eurler method
void PPE::Integrator::integrate(Particle& particle, const Vector3D& force)
{
    // a = F / m
    //Vector3D acceleration = force / particle.getMass();

    // update velocity: v += a * dt
    //Vector3D newVelocity = particle.getVelocity() + acceleration * _dt;
    //particle.setVelocity(newVelocity);

    // update position: x += v * dt
    //Vector3D newPosition = particle.getPosition() + newVelocity * _dt;
    //particle.setPosition(newPosition);

    // update acceleration
    //particle.setAcceleration(acceleration);
}