//
// Created by Krzysiek on 26.04.2017.
//

#include "Figure.h"
#include <list>
#include <random>
using namespace geometria;

int main(){
    srand((unsigned int) time(NULL));
    std::list<Ksztalt*> lista;
    for(int i=0; i<10; ++i){
        int c=rand()%3;
        if(c==0){
            Kwadrat k;
            lista.emplace_back(&k);
        }
        if(c==1){
            Trojkat k;
            lista.emplace_back(&k);
        }
        if(c==2){
            Kolo k;
            lista.emplace_back(&k);
        }
    }

    for(auto n: lista){
        n->Rysuj();
    }
/*
    W efekcie wywołując metodę Rysuj() dla każdego elementu listy
    rysowane są różne figury, czyli wirtualna metoda klasy Ksztalt
    została przeładowana przez metody odpowiednich klas potomnych.
    */

    return 0;
}
