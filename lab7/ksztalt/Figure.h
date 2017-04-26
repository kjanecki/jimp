//
// Created by Krzysiek on 26.04.2017.
//

#ifndef JIMP_EXERCISES_FIGURE_H
#define JIMP_EXERCISES_FIGURE_H

#include <iostream>

namespace geometria{

    class Ksztalt{
    public:
        virtual void Rysuj()=0;
    };

    class Kwadrat:public Ksztalt{
    public:
        void Rysuj();
    };

    class Trojkat:public Ksztalt{
    public:
        void Rysuj();
    };

    class Kolo:public Ksztalt{
    public:
        void Rysuj();
    };
}

#endif //JIMP_EXERCISES_FIGURE_H
