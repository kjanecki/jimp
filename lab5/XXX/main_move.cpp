//
// Created by Krzysiek on 30.03.2017.
//

#include "XXX.h"

//konstruktor przenoszący:
XXX::XXX(XXX &&xxx) : name_{nullptr} {
    swap(name_,xxx.name_);
    //Bardzo popularna szutczka
    //wiemy, ze za chwilę xxx zostanie zniszczony
    //za pomocą destrukotra, więc inicjalizujemy
    //this na nullptr i wymieniamy się z xxx
    //delete nullptr jest bezpieczna operacją i nic się nie stanie...
}

//operator przenoszący:
XXX & XXX::operator=(XXX &&xxx) {
    //jeśli ktoś wpadł na pomsył x = move(x);
    if (this == &xxx) {
        return xxx;
    }
    //w przyciwynym wypadku mamy x = move(y);
    //musimy sami zwolnic pamięć po x (czyli this):
    delete[] name_;
    //i wreszcie przenosimy stan, ten kod jest
    //jest identyczny więc można by go wydzielić do innej metody...
    name_ = nullptr;
    swap(name_,xxx.name_);
}

