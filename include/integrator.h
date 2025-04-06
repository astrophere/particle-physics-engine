#pragma once

#include "types.h"
#include "vector3d.h"
#include "particle.h"

// TODO: define integrator = integrator

namespace PPE {
    class Integrator
    {
        private:
            PPE_FLOAT _dt;

        public:
            // Constructors
            Integrator(PPE_FLOAT timestep) : _dt(timestep) {}
            Integrator() : _dt(0.017) {}

            // main function
            // TODO: integrate with different methods, with Euler being default
            void integrate(Particle& particle, const Vector3D& force);
    };
}