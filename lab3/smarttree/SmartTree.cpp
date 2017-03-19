//
// Created by Krzysiek on 16.03.2017.
//

#include "SmartTree.h"
#include <iostream>
#include <sstream>
#include <ostream>
#include <string>
#include <string>
#include <memory>

namespace datastructures{

    std::unique_ptr <SmartTree> CreateLeaf(int value){
        std::unique_ptr <SmartTree> node= std::make_unique<SmartTree>();
        node->value=value;
        return node;
    }
    std::unique_ptr <SmartTree> InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree){
        if(!tree){
            return nullptr;
        }
        tree->left=std::move(left_subtree);
        return tree;
    }
    std::unique_ptr <SmartTree> InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree){
        tree->right=std::move(right_subtree);
        return tree;
    }
    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out){
        if(unique_ptr->left){
            PrintTreeInOrder(unique_ptr->left,out);
        }

        *out << std::to_string(unique_ptr->value) << ", ";

        if(unique_ptr->right){
            PrintTreeInOrder(unique_ptr->right,out);
        }
    }

    std::string DumpTree(const std::unique_ptr<SmartTree> &tree){
        if(tree == nullptr){
            return "[none]";
        }
        else{
            return "["+std::to_string(tree->value)+" "+DumpTree(tree->left)+" "+DumpTree(tree->right)+"]";
        }
    }

    std::unique_ptr <SmartTree> RestoreTree(const std::string &tree);
}