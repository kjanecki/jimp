//
// Created by Krzysiek on 15.03.2017.
//
#include "XorCypherBreaker.h"


int main(){
    char c='A';
    string str="aaa";
    str[0]=65;
    cout << str<< "\n";
   std::cout << (107^c) << "\n";

    return 0;
}