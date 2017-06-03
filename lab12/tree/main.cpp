//
// Created by Krzysiek on 03.06.2017.
//

#include <Tree.h>
#include <iostream>

int main(){
    tree::Tree<int> tree {5};
    auto value = tree.Value();
    std::cout << value << " " << tree.Depth() << " " << tree.Size() << std::endl;

    return 0;
}