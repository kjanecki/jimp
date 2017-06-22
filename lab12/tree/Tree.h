//
// Created by Krzysiek on 03.06.2017.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include <typeinfo>
#include <queue>
#include <cmath>
#include <memory>

namespace tree{


    template <class TreeType>
    class Tree{
    public:
        Tree()= default;

        Tree(const TreeType& element){
            node_value=element;
            ++size_;
        }

        void Insert(const TreeType &element) {
            if(element <= node_value){
                if(left_!= nullptr)
                    left_->Insert(element);
                else{
                    left_=std::make_unique<Tree<TreeType>>(element);
                }
            }
            else{
                if(right_!= nullptr)
                    right_->Insert(element);
                else{
                    right_=std::make_unique<Tree<TreeType>>(element);
                }
            }
            ++size_;
        }

        TreeType Value(){
            return node_value;
        }

        bool Find(const TreeType &element) {
            return false;
        }

        std::size_t Depth(size_t depth=0) {
            ++depth;
            std::size_t largest=0;
            if(left_!= nullptr)
                largest=left_->Depth(depth);
            if(right_!= nullptr) {
                std::size_t k = right_->Depth(depth);
                if (k > largest) {
                    largest = k;
                }
            }
            if(depth>largest){
                largest=depth;
            }
            return largest;
        }

        std::vector<TreeType> InOrder(){
            std::vector<TreeType> in_order_;
            SetInOrder(&in_order_);
            return in_order_;
        }

        void SetInOrder(std::vector<TreeType> *vec){
            if(left_!= nullptr)left_->SetInOrder(vec);
            vec->push_back(node_value);
            if(right_!= nullptr)right_->SetInOrder(vec);
        }

        std::vector<TreeType> PostOrder(){
            std::vector<TreeType> post_order_;
            SetPostOrder(&post_order_);
            return post_order_;
        }

        void SetPostOrder(std::vector<TreeType> *vec){
            if(left_!= nullptr)left_->SetPostOrder(vec);
            if(right_!= nullptr)right_->SetPostOrder(vec);
            vec->push_back(node_value);
        }


        std::vector<TreeType> PreOrder(){
            std::vector<TreeType> pre_order_;
            SetPreOrder(&pre_order_);
            return pre_order_;
        }

        void SetPreOrder(std::vector<TreeType> *vec){
            vec->push_back(node_value);
            if(left_!= nullptr)left_->SetPreOrder(vec);
            if(right_!= nullptr)right_->SetPreOrder(vec);

        }


        Tree* Root(){return this;};

        std::size_t Size(){return size_;}

        std::unique_ptr<Tree> left_= nullptr;
        std::unique_ptr<Tree> right_= nullptr;
        TreeType node_value;
        std::size_t size_=0;
    };
}


#endif //JIMP_EXERCISES_TREE_H
