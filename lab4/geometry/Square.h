//
// Created by Krzysiek on 23.03.2017.
//

#ifndef JIMP_EXERCISES_SQUARE_H
#define JIMP_EXERCISES_SQUARE_H

#include "Point.h"



namespace geometry{
    class Square{
    public:
        Square(const Point p1,const Point p2,const Point p3,const Point p4):
                p1_(p1), p2_(p2), p3_(p3), p4_(p4){};

        double Circumference();
        double Area();

        const Point p1_,p2_,p3_,p4_;
    };

}


#endif //JIMP_EXERCISES_SQUARE_H
