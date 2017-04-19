//
// Created by Krzysiek on 18.04.2017.
//

#include "WordCounter.h"
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

    std::ifstream is("C:/Users/Krzysiek/Desktop/studia/semestr 2/JIMP2/exercises/lab6/wordcounter/MyFile.txt");
    if(is.is_open()){
        std::cout << "no kurde";
    }
    WordCounter w{Word("raz"),Word("dwa"),Word("trzyy"),Word("raz")};
    std::cout << w << "\n\n";
    WordCounter w2 = WordCounter::FromInputStream(&is);
    is.close();
    std::cout << w2;
    return 0;
}