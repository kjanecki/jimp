//
// Created by Krzysiek on 25.03.2017.
//

#include <iostream>
#include <typeinfo>
#include <vector>
#include "SimpleJson.h"
using ::std::cout;
int main(){

    nets::JsonValue k(2.5);

    cout << k.double_value_ << "\n\n";
    return 0;
};
