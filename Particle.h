//
// Created by Gianluca Cientanni on 15/03/2017.
//

#ifndef EX3_3_PARTICLE_H
#define EX3_3_PARTICLE_H

#include "Vector.h"


class Particle {

public:

    Particle (double r=1, const Vector&p=Vector(), const Vector&v=Vector()) : radius(r), p(p), v(v) {;}

    void setPosition(Vector v){p = v;}
    Vector getPosition() const {return p;}

    void setVelocity(Vector w){v = w;}
    Vector getVelocity() const {return v;}

    double getRadius() const {return radius;}

    void move(double t);

    double timeToCollision(const Particle&particle);
    void collideParticles(Particle&particle);

private:

    Vector p;
    Vector v;
    double radius;

};


#endif //EX3_3_PARTICLE_H
