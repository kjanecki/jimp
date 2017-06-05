//
// Created by Krzysiek on 03.06.2017.
//

#include <Tree.h>
#include <iostream>
#include <memory>

int main(){
    int k=0;
    std::unique_ptr<int> pt= std::make_unique<int>(k);
    std::unique_ptr<int> pt2 = move(pt);
    std::cout<<*pt2 << "\n";


    return 0;
}