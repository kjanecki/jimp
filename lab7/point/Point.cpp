//
// Created by Krzysiek on 23.04.2017.
//


#include "Point.h"
#include <cmath>
#include <iostream>

using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;
using ::std::cout;

namespace algebra{
    /* Aby wskazać, ze definicja funkcji dotyczy metody danej klasy
      stosujemy tzw. operator zasięgu - "::"
    */

    //Specjalna inicjalizacja zmiennych. Zmienne są inicjowane
    //nim zostanie wywołane ciało konstruktora
    Point::Point():x_(0),y_(0){
        //cout << "Konstruktor bezparametrowy Punkt" << endl;
    }

    Point::Point(double x, double y){
        //cout << "Konstruktor parametrowy Punkt" << endl;
        x_ = x;
        y_ = y;
    }

    Point::~Point(){
       // cout << "Destruktor Punkt" << endl;
       // cout << endl;
    }

    double Point::Distance(const Point &other) const {
        double result = sqrt(pow(GetX() - other.GetX(), 2) + pow(GetY() - other.GetY(), 2));
        return result;
    }

    void Point::ToString(ostream *out) const{
        (*out) << "(" << GetX() << ";" << GetY() << ")";
    }
}