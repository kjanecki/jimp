//
// Created by Krzysiek on 05.03.2017.
//

#include "DoubleBasePalindromes.h"
#include <iostream>
#include <string>
using namespace std;

uint64_t DoubleBasePalindromes(int max_vaule_exculsive){
    uint64_t sum=0;
    return sum;
}

string binary(int value){
    string str="";
    while(value>0){
        if(value%2==0){
            str="0"+str;
        }
        else{
            str="1"+str;
        }
        value/=2;
    }
    return str;
}