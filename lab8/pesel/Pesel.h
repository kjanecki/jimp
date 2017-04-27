//
// Created by Krzysiek on 26.04.2017.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <iostream>
#include <stdexcept>

namespace academia{

    class AcademiaDataValidationError:public std::runtime_error{
    public:
        AcademiaDataValidationError(const std::string &__arg):std::runtime_error(__arg),str_(__arg){};
        virtual ~AcademiaDataValidationError(){};

        std::string str_;
    };

    class InvalidPeselLength:public AcademiaDataValidationError{
    public:

        InvalidPeselLength(const std::string &str, int length):AcademiaDataValidationError(str){};
    };

    class InvalidPeselChecksum:public AcademiaDataValidationError{
    public:
        InvalidPeselChecksum(const std::string &str, int sum):AcademiaDataValidationError(str){};
    };

    class InvalidPeselCharacter:public AcademiaDataValidationError{
    public:
        InvalidPeselCharacter(const std::string &str):AcademiaDataValidationError(str){};
    };


    class Pesel{
    public:
        Pesel()= delete;
        Pesel(const std::string &str):pesel_(str){
            ValidatePESEL(pesel_);
        };
        std::string GetString(){return pesel_;};
    private:
        void ValidatePESEL(const std::string &str);
        std::string pesel_;
    };

}


#endif //JIMP_EXERCISES_PESEL_H
