//
// Created by Krzysiek on 18.04.2017.
//

#include "WordCounter.h"
//#include <iostream>
//#include <fstream>
using ::datastructures::Word;
using ::datastructures::WordCounter;

int main(){
    datastructures::Counts c1,c2;
    ++c2;
    if(c2>c1){
        std::cout<< "hello "<< "\n";
    }
    ++c1;
    if(c2>c1){
        std::cout<< "hello 2"<< "\n";
    }

    if(c2==c1){
        std::cout<< "hello 3"<< "\n";
    }

   //std::ifstream kk("asdasd");
    WordCounter w{Word("raz"),Word("dwa")};
    //WordCounter w2 = WordCounter::FromInputStream(&kk);
    //kk.close();
    return 0;
}