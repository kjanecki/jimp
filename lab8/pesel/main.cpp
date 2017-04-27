//
// Created by Krzysiek on 26.04.2017.
//

#include <iostream>
#include "Pesel.h"

using namespace academia;
int main(){

    try{
        Pesel p{"44051401359"};
    }catch(const InvalidPeselChecksum &arg){
        std::cerr << arg.what() << "\n";
    }catch(const InvalidPeselLength &arg){
        std::cerr << arg.what() << "\n";
    }catch(const InvalidPeselCharacter &arg){
        std::cerr << arg.what() << "\n";
    }


    return 0;
}