//
// Created by Krzysiek on 04.03.2017.
//

#include "Palindrome.h"
#include <string>

bool is_palindrome(std::string str){
    int len=str.length();
    for (int i=0;i<len/2;i++){
        if(str[i]!=str[len-1-i])
            return false;
    }
    return true;
}