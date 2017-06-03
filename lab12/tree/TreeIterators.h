//
// Created by Krzysiek on 03.06.2017.
//

#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H

#include <Tree.h>
#include <vector>

namespace tree{



    template <class Type>
    class InOrderTreeIterator{
    public:
        InOrderTreeIterator(Node<Type> *present_node){
            InOrder(present_node);
            present_node_=in_order_view_[present_index_];
        }
        void InOrder(Node<Type> *present_node){
            if(present_node){
                InOrder(present_node->left_);
                in_order_view_.push_back(present_node);
                InOrder(present_node->right_);
            }
        }
        InOrderTreeIterator &operator++(){

            present_node_=in_order_view_[++present_index_];
        }

        Type operator*(){ return present_node_->value_;}

        template <class OperatorType>
        friend bool operator!=(const InOrderTreeIterator& it1,const InOrderTreeIterator& it2);

        Node<Type> *present_node_= nullptr;
        int present_index_=0;
        std::vector<Node<Type>*> in_order_view_;
    };

    template <class OperatorType>
    bool operator!=(const InOrderTreeIterator<OperatorType>& it1,const InOrderTreeIterator<OperatorType>& it2){
        return it1.present_node_!=it2.present_node_;
    }

    template <class Type>
    class InOrder{
    public:
        InOrder(Tree<Type> *tree){};
    private:
    };

    template <class Type>
    class InOrderTreeView{
    public:
        InOrderTreeView(Tree<Type> *tree){};

    };
}


#endif //JIMP_EXERCISES_TREEITERATORS_H
