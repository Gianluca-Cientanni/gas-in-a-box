cmake_minimum_required(VERSION 3.6)
project(Ex3_3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Vector.cpp Vector.h functions.cpp functions.h Particle.cpp Particle.h Box.cpp Box.h random.h random.cpp)
add_executable(Ex3_3 ${SOURCE_FILES} Vector.cpp Vector.h functions.cpp functions.h Particle.cpp Particle.h)