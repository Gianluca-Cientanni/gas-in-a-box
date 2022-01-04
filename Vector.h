//
// created by gianluca cientanni on 28/02/2017.
//

#ifndef ex3_3_vector_h
#define ex3_3_vector_h


class vector {  //creating a class called vector to declare and (in some cases) define functions.

public:

    vector(double x=0, double y=0, double z=0) : x(x), y(y), z(z) {;}   //initialising the variables x,y,z as zero by default if not defined later.

    void setx(double v){x = v;}
    double getx() const {return x;}

    void sety(double v) {y = v;}
    double gety() const {return y;}

    void setz(double v) {z = v;}
    double getz() const {return z;}

    double modsqr() const;  //
    double mod() const;
    double dot(const vector & v) const ;
    double distance(const vector&v) const;

    void scale(double f);
    vector unit();
    vector cross(const vector&v) const ;

    vector & operator+=(const vector&v){

        x+=v.x;
        y+=v.y;
        z+=v.z;
        return *this;
    }
   vector operator+(const vector&v){

       vector v2(*this);
       return v2+=v;
   }
    vectorvectorvector & operator-=(const vector&v){

        x-=V.x;
        y-=V.y;
        z-=V.z;
        return *this;
    }
    Vector operator-(const Vector&V){

        Vector v2(*this);
        return v2-=V;
    }
    Vector operator-()const {

        Vector V(x,y,z);
        V.x = -x;
        V.y = -y;
        V.z = -z;

        return V;

    }


private:

    double x,y,z;


};





#endif //EX3_3_VECTOR_H
