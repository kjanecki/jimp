//
// Created by Krzysiek on 25.05.2017.
//

#ifndef JIMP_EXERCISES_BINARYTREE_H
#define JIMP_EXERCISES_BINARYTREE_H


template <class T>
class Node{
private:
    Node()= delete;
    Node(T value):value_(value){};

private:
    T value_;
    Node *left_;
    Node *right_;
};

template <class T>
class BinaryTree{
public:
    BinaryTree(T value){
        root_=new Node{value};
    }

private:
    Node *root_;
};
#endif //JIMP_EXERCISES_BINARYTREE_H

