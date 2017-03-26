//
// Created by Krzysiek on 25.03.2017.
//

#include <iostream>
#include <typeinfo>
#include <vector>
#include "SimpleJson.h"
#include <string>

using ::std::cout;
int main(){

    std::string str=R"("\"abc\"")";
    std::string k=str;

    cout << k << "\n\n";
    return 0;
};
