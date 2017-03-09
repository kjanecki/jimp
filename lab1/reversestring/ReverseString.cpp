//
// Created by Krzysiek on 04.03.2017.
//

#include "ReverseString.h"

std::string reverse(std::string str){
    if(str==""){
        return "";
    }
    const char *character=str.c_str();
    std::string str2="";
    if(*character!='\0'){
        str2=reverse(std::string(character+1));
    }
    return std::string(str2+*character);
}

