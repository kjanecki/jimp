//
// Created by Krzysiek on 30.03.2017.
//

#include "XXX.h"


XXX::XXX() : name_{new char[1024]} {

};
//konstruktory parametryczne
XXX::XXX(int param){};

XXX::XXX(const std::string name){};

//Rule of five://

//1. konstruktor kopiujący
//XXX::XXX(const XXX &xxx){};
//2. konstruktor przenoszący
//XXX::XXX(XXX &&xxx){};
//3. operator przypisania kopiujący
//XXX & XXX::operator=(const XXX &xxx){};
//4. operator przypisania przenoszący
//XXX & XXX::operator=(XXX &&xxx){};
//5. Destruktor

XXX::~XXX() {
    delete [] name_;
};
