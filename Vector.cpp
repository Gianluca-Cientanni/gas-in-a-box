//
// Created by Gianluca Cientanni on 28/02/2017.
//

#include "Vector.h"
#include <cmath>



    double Vector::modSqr() const {

        double modulusSqr = pow(x, 2) + pow(y, 2) + pow(z, 2);
        return modulusSqr;

    }


    double Vector::mod() const {

    double modulus = sqrt(pow(x,2) + pow(y,2) + pow(z,2));
        return modulus;

    }

    double Vector::dot(const Vector &V) const {

        double vu = V.getX()*x + V.getY()*y + V.getZ()*z;
        return vu;

    }

    double Vector::distance(const Vector &V) const {

        Vector dsqr(x-V.x,y-V.y,z-V.z);
        return dsqr.mod();

    }

    void Vector::scale(double f){
    x=f*x;
    y=f*y;
    z=f*z;
    }

    Vector Vector::unit(){
    Vector v(x,y,z);
    v.scale(1/(v.mod()));
    return v;
    }

    Vector Vector::cross(const Vector&V) const {
    Vector u(x,y,z);
    Vector w((u.y)*V.z - (u.z)*V.y, (u.z)*V.x - (u.x)*V.z , (u.x)*V.y - (u.y)*V.x);

    return w;
    }

