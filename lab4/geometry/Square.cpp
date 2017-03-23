//
// Created by Krzysiek on 23.03.2017.
//

#include "Square.h"
#include "Point.h"

namespace geometry{

    double Square::Circumference(){
        double circum;
        circum=p1_.Distance(p2_);
        if(circum!=p2_.Distance(p3_))
            return 0;
        if(circum!=p3_.Distance(p4_))
            return 0;
        if(circum!=p4_.Distance(p1_))
            return 0;
        if(circum!=p3_.Distance(p1_))
            return 0;
        return 4*circum;
    }

    double Square::Area(){
        double square_area=p1_.Distance(p2_)*p2_.Distance(p3_);
        return square_area;
    }
}
