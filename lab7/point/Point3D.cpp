//
// Created by Krzysiek on 23.04.2017.
//

#include "Point3D.h"
#include "cmath"
using ::std::sqrt;
using ::std::pow;

namespace algebra{
    Point3D::Point3D():z_(0) {
       std::cout << "konstruktor bezparametrowy Point3D" << std::endl;
    }

    Point3D::Point3D(double x, double y, double z):Point(x,y),z_(z){
        std::cout << "konstruktor parametrowy Point3D" << std::endl;
    };

    Point3D::~Point3D() {
        std::cout<< "Destruktor Point3D" << std::endl;
    }

    double Point3D::Distance(Point3D p) const{
        return sqrt(pow(this->GetX()-p.GetX(),2)+
                    pow(this->GetY()-p.GetY(),2)+
                    pow(this->GetZ()-p.GetZ(),2));
    }

}
