//
// Created by Gianluca Cientanni on 17/03/2017.
//

#ifndef EX3_3_BOX_H
#define EX3_3_BOX_H


#include <vector>
#include "Particle.h"

class Box {

public:

    Box (double size = 500) : size(size) {;}

    std::vector <Particle> particles;

    void addParticle (const Particle &particle);
    double timeToWallCollision (int wall, const Particle&particle);
    void doWallCollision (int wall, Particle&particle);
    double step();
    std::vector<int> nParticlesOctant() const;


private:
    double size;




};


#endif //EX3_3_BOX_H
