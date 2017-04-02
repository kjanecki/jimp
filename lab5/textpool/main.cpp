//
// Created by Krzysiek on 02.04.2017.
//
#include "TextPool.h"
#include <iostream>

int main(){
    pool::TextPool ech{};
    pool::TextPool s1{"abc","cdf","ghi","abc"};
    s1.Intern("ghij");
    std::cout << s1.StoredStringCount() << std::endl;

    return 0;
}

