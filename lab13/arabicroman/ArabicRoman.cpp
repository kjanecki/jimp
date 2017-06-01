//
// Created by Krzysiek on 01.06.2017.
//

#include "ArabicRoman.h"
#include <map>


std::map<char,int> hash_map={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

int RomanToArabic(std::string roman){
    int result=0;
    for(int i=0; i<roman.size();++i){
        if(i<roman.size()-1){
            int present=hash_map.find(roman[i])->second;
            int next=hash_map.find(roman[i+1])->second;
            if(next>present){
                result+=next-present;
                ++i;
            } else{
                result+=present;
            }
        }
        else{
            result+=hash_map.find(roman[i])->second;
        }
    }
    return result;
}