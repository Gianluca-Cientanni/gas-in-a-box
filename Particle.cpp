//
// Created by Gianluca Cientanni on 15/03/2017.
//

#include <cfloat>
#include <cmath>
#include <iostream>
#include "Particle.h"
#include "functions.h"

void Particle::move(double t) {

    Vector delta = v;
    delta.scale(t);
    p += delta;

}

double Particle::timeToCollision(const Particle&particle){

    Vector r0 = particle.getPosition() - p;
    Vector v0 = particle.getVelocity() - v;
    if(v0.mod()<0.000001){return FLT_MAX;}

    double tca = ((-1)*(r0.dot(v0)))/(v0.modSqr());
    if(tca<0){return FLT_MAX;}

    Vector s = v0;
    s.scale(tca);

    double bsqr = r0.modSqr() - s.modSqr();
    double dsqr = 4*(pow(radius,2)) - bsqr;
    if(dsqr > 4*radius){return FLT_MAX;}

    double tcol = tca - (sqrt(dsqr)/v0.mod());
    if(tcol > 0){return tcol;}

    else{return FLT_MAX;}

}

void Particle::collideParticles(Particle &particle) {

    double t = timeToCollision(particle);
    if(t < 0 || t==FLT_MAX){return;}

    move(t);
    particle.move(t);

    Vector r0 = particle.getPosition() - p;
    Vector n = r0.unit();
    Vector v1 = n;
    Vector v2 = n;

    v1.scale((v.dot(n)));
    v2.scale((particle.v.dot(n)));

    Vector deltaV = v2 - v1;

    setVelocity(v + deltaV);
    particle.setVelocity(particle.v - deltaV);


}
