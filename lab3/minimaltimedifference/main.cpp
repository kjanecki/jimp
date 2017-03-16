//
// Created by Krzysiek on 16.03.2017.
//

#include "MinimalTimeDifference.h"
#include <regex>
#include <iostream>

int main(){

    std::regex pattern {R"((\d{1,2}):(\d{2}))"};
    std::string str="12:29";
    std::smatch matches;
    if (regex_match(str, matches, pattern)){

    }

    return 0;
}
