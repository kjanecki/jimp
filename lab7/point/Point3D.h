//
// Created by Krzysiek on 23.04.2017.
//

#ifndef JIMP_EXERCISES_POINT3D_H
#define JIMP_EXERCISES_POINT3D_H

#include "Point.h"

namespace algebra{
    class Point3D: public Point{
    public:
        Point3D();

        Point3D(double x, double y, double z);

        ~Point3D();

        double Distance(Point3D) const;

        double GetZ() const {return z_;}

    private:
        double z_;
    };

}

#endif //JIMP_EXERCISES_POINT3D_H
