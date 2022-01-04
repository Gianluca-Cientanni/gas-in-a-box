#include <iostream>
#include "functions.h"
#include "Box.h"
#include "random.h"
#include <fstream>

int main() {

bool (t1) = test1();    // This is a bool t1 to test whether the functions GetX/Y/Z and SetX/Y/Z work by testing whether 'value' and 'test' are the same.

    if(t1){

        std::cout << "Test 1 : SUCCESS" << std::endl; //True condition, occurs when no tests return fail.

    } else{

        std::cout << "Test 1 : FAILED" << std::endl; //False condition, occurs when any of the test fail.
    }

    if(testModulus()){

        std::cout << "Test Modulus : SUCCESS" << std::endl;

    } else{

        std::cout << "Test Modulus : FAILED" << std::endl;

    }

    if(testDistance()){

        std::cout << "Test Distance : SUCCESS" << std::endl;

    } else{

        std::cout << "Test Distance : FAILED" << std::endl;

    }

    if(testDot()){

        std::cout << "Test Dot : SUCCESS" << std::endl;

    } else{

        std::cout << "Test Dot : FAILED" << std::endl;

    }

    if(testScale()){

        std::cout << "Test Scale : SUCCESS" << std::endl;

    } else{

        std::cout << "Test Scale : FAILED" << std::endl;

    }

    if(testUnit()){

        std::cout << "Test Unit : SUCCESS" << std::endl;

    } else{

        std::cout << "Test Unit : FAILED" << std::endl;

    }

    if(testCross()){

        std::cout << "Test Cross : SUCCESS" << std::endl;

    } else{

        std::cout << "Test Cross : FAILED" << std::endl;

    }

    if(testOperators()){

        std::cout << "Test Operators : SUCCESS" << std::endl;

    } else{

        std::cout << "Test Operators : FAILED" << std::endl;

    }

    if(testParticle()){

        std::cout << "Test Particle : SUCCESS" << std::endl;

    } else{

        std::cout << "Test Particle : FAILED" << std::endl;

    }

    if(testMove()){

        std::cout << "Test Move : SUCCESS" << std::endl;

    } else{

        std::cout << "Test Move : FAILED" << std::endl;

    }

    if(testCollision()){

        std::cout << "Test Collision : SUCCESS" << std::endl;

    } else{

        std::cout << "Test Collision : FAILED" << std::endl;

    }

    if(testCollideParticles()){

        std::cout << "Test Particle Collision : SUCCESS" << std::endl;

    } else{

        std::cout << "Test Particle Collision : FAILED" << std::endl;

    }

    if(testWallCollision()){

        std::cout << "Test Wall Collision : SUCCESS" << std::endl;

    } else{

        std::cout << "Test Wall Collision : FAILED" << std::endl;

    }


    Box box;

    double time = 0;

    for(int i=0; i<1000; ++i){
        Particle p (1,Vector(249*float(std::rand())/RAND_MAX, 249*float(std::rand())/RAND_MAX, 249*float(std::rand())/RAND_MAX), Vector(Random::randomNorm(0,10),Random::randomNorm(0,10),Random::randomNorm(0,10)));
        box.addParticle(p);
    }


    std::ofstream ParticleMap;
    ParticleMap.open("particles.txt");

    ParticleMap << 0 << " " << 0 << " " << 1000 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << std::endl;

    for(int i=1; i<=10000; ++i){

        time += box.step();

        if(i%100==0){

            ParticleMap << i << " " << time << " " << box.nParticlesOctant()[0]
                        << " " << box.nParticlesOctant()[1]
                    << " " << box.nParticlesOctant()[2]
                    << " " << box.nParticlesOctant()[3]
                    << " " << box.nParticlesOctant()[4]
                    << " " << box.nParticlesOctant()[5]
                    << " " << box.nParticlesOctant()[6]
                    << " " << box.nParticlesOctant()[7] << std::endl;
        }

    }
    ParticleMap.close();



    return 0;
}