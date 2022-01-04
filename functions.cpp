//
// Created by Gianluca Cientanni on 02/03/2017.
//

#include <cstdlib>
#include <vector>
#include <iostream>
#include <cfloat>
#include "functions.h"
#include "vector.h"
#include "cmath"
#include "Particle.h"
#include "Box.h"


bool testFloat(double value, double test, double p){


    double diff = value - test;

    if(std::abs(diff) < p){
        return true;
    } else {
        return false;
    }
}

bool test1(){

    Vector V;

    if (!testFloat(V.getX(), 0, 0.0001)){return false;}
    if (!testFloat(V.getY(), 0, 0.0001)){return false;}
    if (!testFloat(V.getZ(), 0, 0.0001)){return false;}

    V.setX(10.0);
    V.setY(20.0);
    V.setZ(30.0);

    if(!testFloat(V.getX(), 10.0, 0.0001)){return false;}
    if(!testFloat(V.getY(), 20.0, 0.0001)){return false;}
    if(!testFloat(V.getZ(), 30.0, 0.0001)){return false;}

    return true;

}

bool testModulus() {


    Vector v(1,2,3);
    if (!testFloat(v.modSqr(),14,0.0001)){return false;}
    if (!testFloat(v.mod(), sqrt(14),0.0001)){return false;}
    return true;


}

bool testDistance(){

    Vector v1(1,2,3);
    Vector v2(3,2,1);
    if(!testFloat(v1.distance(v2),2*sqrt(2),0.0001)){return false;}
    return true;

}

bool testDot(){

    Vector v1(1,0,1);
    Vector v2(0,1,0);

    if(!testFloat(v1.dot(v2),0,0.0001)){return false;}
    return true;

}

bool testScale(){

    Vector v1(1,1,1);
    v1.scale(3);

    if(!testFloat(v1.getX(),3,0.0001)){return false;}
    if(!testFloat(v1.getY(),3,0.0001)){return false;}
    if(!testFloat(v1.getZ(),3,0.0001)){return false;}

    return true;
}

bool testUnit(){

    Vector v1(3,3,3);
    Vector v2 = v1.unit();
    if(!testFloat(v2.mod(),1,0.0001)){return false;}
    if(!testFloat(v1.dot(v2),v1.mod(),0.0001)){return false;}
    return true;

}

bool testCross(){

    Vector v1(1,0,0);
    Vector v2(0,1,0);
    Vector v3(0,0,1);

    Vector v4 = v1.cross(v2);
    Vector v5 = v2.cross(v3);
    Vector v6 = v3.cross(v1);

    if(!testFloat(v4.distance(v3),0,0.0001)){return false;}
    if(!testFloat(v5.distance(v1),0,0.0001)){return false;}
    if(!testFloat(v6.distance(v2),0,0.0001)){return false;}
    return true;

}

bool testOperators(){

    Vector v1(1,2,3);
    Vector v2(2,4,6);
    Vector v3 = v1 + v1;
    if(!testFloat(v3.distance(v2),0,0.0001)){return false;}

    Vector v4 = v2 - v1;
    if(!testFloat(v4.distance(v1),0,0.0001)){return false;}

    Vector v5 = -v1;
    Vector v6(-1,-2,-3);
    if(!testFloat((v5.distance(v6)),0,0.0001)){return false;}
    return true;


}

bool testParticle(){

    Particle P;
    Vector v1(0,0,0);
    if(!testFloat(P.getPosition().distance(v1),0,0.0001)){return false;}
    if(!testFloat(P.getVelocity().distance(v1),0,0.0001)){return false;}

    P.setPosition(Vector(1,2,3));
    P.setVelocity(Vector(4,5,6));

    Vector v2(1,2,3);
    Vector v3(4,5,6);

    if(!testFloat(P.getPosition().distance(v2),0,0.0001)){return false;}
    if(!testFloat(P.getVelocity().distance(v3),0,0.0001)){return false;}

    return true;

}

bool testMove(){

    Particle p;
    p.setPosition(Vector(0,0,0));
    p.setVelocity(Vector(1,1,1));
    p.move(1);
    Vector v1(1,1,1);
    if(!testFloat(p.getPosition().distance(v1),0,0.0001)){return false;}
    return true;

}

bool testCollision(){


    Particle p1 (1, Vector (0,0,0), Vector (1,0,0));
    Particle p2 (1, Vector (12,0,0), Vector (-1,0,0));
    double t = p1.timeToCollision(p2);
    if(!testFloat(t,5,0.0001)){return false;}

    Particle p3 (1, Vector (0,0,0), Vector (1,1,0));
    Particle p4 (1, Vector (5,5,6.99999), Vector (0,0,-1));
    double t2 = p3.timeToCollision(p4);
    if(!testFloat(t2, 5, 0.0001)){return false;}

    Particle p5 (1, Vector(0,3,0), Vector(1,0,0));
    Particle p6 (1, Vector(12,0,0), Vector(-1,0,1));
    double t3 = p5.timeToCollision(p6);
    if(!testFloat(t3,FLT_MAX,0.0001)){return false;}
    return true;
}

bool testCollideParticles(){

    Particle p1 (1, Vector(0,0,0), Vector(1,0,0));
    Particle p2 (1, Vector(5,0,0), Vector(0,0,0));

    p1.collideParticles(p2);

    Vector v1(0,0,0);
    Vector v2 (1,0,0);

    if(!testFloat(v1.distance(p1.getVelocity()),0,0.0001)){return false;}
    if(!testFloat(v2.distance(p2.getVelocity()),0,0.0001)){return false;}

    Particle p3 (1, Vector(0,0,0), Vector(1,0,0));
    Particle p4 (1, Vector(10,0,0), Vector(-0.5,0,0));

    p3.collideParticles(p4);

    if(!testFloat(p3.getVelocity().getX(),-0.5,0.0001)){return false;}
    if(!testFloat(p4.getVelocity().getX(), 1,0.0001)){ return false;}

    return true;

}

bool testWallCollision() {

    Box box;
    Particle p (1, Vector(0,0,0), Vector(1,0,0));
    double t = box.timeToWallCollision(1,p);

    if(!testFloat(t, 250, 0.0001)){return false;}
    return true;
}

