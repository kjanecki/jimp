//
// Created by Krzysiek on 26.04.2017.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

namespace academia{

    class Pesel{
    public:
        Pesel()= delete;
        Pesel(const char *c):c_(c){

        };
        void ValidatePesel(const char *c);


        const char*c_;
    };

}


#endif //JIMP_EXERCISES_PESEL_H
