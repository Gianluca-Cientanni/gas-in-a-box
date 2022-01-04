//
// Created by Gianluca Cientanni on 17/03/2017.
//

#include <cfloat>
#include <iostream>
#include "Box.h"
#include <vector>


void Box::addParticle(const Particle &particle) {


    particles.push_back(particle);
}

double Box::timeToWallCollision(int wall, const Particle &particle) {

    double s = size/2;
    double t;

    if(wall==1){

        if(particle.getVelocity().getX()>0){

            t = (s - particle.getPosition().getX())/particle.getVelocity().getX();
            return t;
        }
        else if(particle.getVelocity().getX()<0){

            t = (-s - particle.getPosition().getX())/particle.getVelocity().getX();
            return t;
        }
        else{return FLT_MAX;}
    }

    if(wall==2){
        if(particle.getVelocity().getY()>0){

            t = (s - particle.getPosition().getY())/particle.getVelocity().getY();
            return t;
        }
        else if(particle.getVelocity().getY()<0){

            t = (-s - particle.getPosition().getY())/particle.getVelocity().getY();
            return t;
        }
        else{return FLT_MAX;}
    }

    if(wall==3){
        if(particle.getVelocity().getZ()>0){

            t = (s - particle.getPosition().getZ())/particle.getVelocity().getZ();
            return t;
        }
        else if(particle.getVelocity().getZ()<0){

            t = (-s - particle.getPosition().getZ())/particle.getVelocity().getZ();
            return t;
        }
        else{return FLT_MAX;}
    }

}

void Box::doWallCollision(int wall, Particle &particle) {

    double t = timeToWallCollision(wall,particle);
    particle.move(t);
    if(wall==1){

        particle.setVelocity(Vector (-particle.getVelocity().getX(), particle.getVelocity().getY(),particle.getVelocity().getZ()));
    }
    else if(wall==2){

        particle.setVelocity(Vector (particle.getVelocity().getX(), -particle.getVelocity().getY(),particle.getVelocity().getZ()));
    }
    else if(wall==3){

        particle.setVelocity(Vector (particle.getVelocity().getX(), particle.getVelocity().getY(),-particle.getVelocity().getZ()));
    }
}

double Box::step(){

    double timeToNextCollision = FLT_MAX;
    int collisionType = 0;
    int collider1 = -1;
    int collider2 = -1;

    for(int i=0; i<particles.size();++i ) {

        double t1 = timeToWallCollision(1, particles[i]);
        double t2 = timeToWallCollision(2, particles[i]);
        double t3 = timeToWallCollision(3, particles[i]);

        if (t1 < t2 && t1 < t3) {

            if (t1 < timeToNextCollision) {

                timeToNextCollision = t1;
                collider1 = i;
                collisionType = 1;
            }
        }
        if (t2 < t1 && t2 < t3) {

            if (t2 < timeToNextCollision) {

                timeToNextCollision = t2;
                collider1 = i;
                collisionType = 2;
            }
        }
        if (t3 < t1 && t3 < t2) {

            if (t3 < timeToNextCollision) {

                timeToNextCollision = t3;
                collider1 = i;
                collisionType = 3;
            }
        }
    }

    for(int i=0; i<particles.size(); ++i ){

            for(int j = 0; j<particles.size(); ++j) {
                if(i!=j) {


                    double t = particles[i].timeToCollision(particles[j]);

                    if (t < timeToNextCollision) {

                        timeToNextCollision = t;
                        collisionType = 0;
                        collider1 = i;
                        collider2 = j;

                    }
                }
            }
    }

    if(collisionType==0){
        particles[collider1].collideParticles(particles[collider2]);
    }
    if(collisionType==1){
        doWallCollision(1,particles[collider1]);
    }
    if(collisionType==2){
        doWallCollision(2,particles[collider1]);
    }
    if(collisionType==3){
        doWallCollision(3,particles[collider1]);
    }

    for(int i=0;i<particles.size();++i){

        if(i!=collider1 && i!=collider2){

            particles[i].move(timeToNextCollision);
        }

    }

    return timeToNextCollision;
}

std::vector<int> Box::nParticlesOctant() const {
    std::vector<int> nParticles;
    nParticles.resize(8);

    for(int i=0; i<particles.size(); ++i){

        if(particles[i].getPosition().getX() > 0 && particles[i].getPosition().getY() > 0 && particles[i].getPosition().getZ() > 0){
            nParticles[0] += 1;
        }
        if(particles[i].getPosition().getX() > 0 && particles[i].getPosition().getY() > 0 && particles[i].getPosition().getZ() < 0){
            nParticles[1] += 1;
        }
        if(particles[i].getPosition().getX() > 0 && particles[i].getPosition().getY() < 0 && particles[i].getPosition().getZ() > 0){
            nParticles[2] += 1;
        }
        if(particles[i].getPosition().getX() > 0 && particles[i].getPosition().getY() < 0 && particles[i].getPosition().getZ() < 0){
            nParticles[3] += 1;
        }
        if(particles[i].getPosition().getX() < 0 && particles[i].getPosition().getY() > 0 && particles[i].getPosition().getZ() > 0){
            nParticles[4] += 1;
        }
        if(particles[i].getPosition().getX() < 0 && particles[i].getPosition().getY() > 0 && particles[i].getPosition().getZ() < 0){
            nParticles[5] += 1;
        }
        if(particles[i].getPosition().getX() < 0 && particles[i].getPosition().getY() < 0 && particles[i].getPosition().getZ() > 0){
            nParticles[6] += 1;
        }
        if(particles[i].getPosition().getX() < 0 && particles[i].getPosition().getY() < 0 && particles[i].getPosition().getZ() < 0){
            nParticles[7] += 1;
        }

    }

    return nParticles;
}

