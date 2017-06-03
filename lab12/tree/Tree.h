//
// Created by Krzysiek on 03.06.2017.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include <typeinfo>
#include <queue>
#include <cmath>

namespace tree{


    template <class Type>
    class Node{
        template <class TreeType>
        friend class Tree;
    public:
        Node(Type value):value_(value){};

    private:
        Type value_;
        Node* left_= nullptr;
        Node* right_= nullptr;
    };

    template <class TreeType>
    class Tree{
    public:
        Tree()= default;

        Tree(const TreeType& element){
            Insert(element);
        }

        void Insert(const TreeType &element) {
           // Node<TreeType> *new_node= new Node<TreeType>(element);
            if(!root_){
                root_=new Node<TreeType>(element);
                ++size_;
            }
            else{
                int flag=0;
                Node<TreeType> *node=root_;
                while(flag==0){
                    if(element<=node->value_){
                        if(!node->left_){
                            node->left_=new Node<TreeType>(element);
                            ++size_;
                            flag=1;
                        }
                        else{
                            node=node->left_;
                        }
                    }
                    else{
                        if(!node->right_){
                            node->right_=new Node<TreeType>(element);
                            ++size_;
                            flag=1;
                        }
                        else{
                            node=node->right_;
                        }
                    }
                }
            }
        }

        TreeType Value(){
            return root_->value_;
        }

        bool Find(const TreeType &element) {
            return false;
        }

        std::size_t Depth(size_t depth=0,Node<TreeType> *node= nullptr) {
            if(root_== nullptr){
                return 0;
            }
            if(!node){
                node=root_;
            }
            depth++;
            size_t largest=depth;
            if (node->left_){
                largest=Depth(depth,node->left_);
            }
            if(node->right_){
                auto k=Depth(depth, node->right_);
                if(k>largest){
                    largest=k;
                }
            }

            return largest;

        }

        std::size_t Size(){return size_;}

        ~Tree() {
            if(root_!= nullptr)
            {
                std::queue<Node<TreeType>*> Q;
                Q.push(root_);
                while(!Q.empty()){
                    if(Q.front()->left_!= nullptr)
                        Q.push(Q.front()->left_);
                    if(Q.front()->right_!= nullptr)
                        Q.push(Q.front()->right_);
                    delete(Q.front());
                    Q.pop();
                    size_--;
                }
            }
        }

    private:
        Node<TreeType> *root_= nullptr;
        std::size_t size_=0;
    };




}


#endif //JIMP_EXERCISES_TREE_H
