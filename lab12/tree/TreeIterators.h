//
// Created by Krzysiek on 03.06.2017.
//

#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H

#include <Tree.h>
#include <vector>
#include <algorithm>

namespace tree{

    template <class Type>
    class InOrderTreeView;

    template <class Type>
    class InOrderTreeIterator{
    public:
        InOrderTreeIterator(Tree<Type> *tree):array_{tree}{
        }

        void operator++(){
            present_index_++;
        }

        Type operator*(){return array_.in_order_view_[present_index_];}

        template <class OperatorType>
        friend bool operator!=(const InOrderTreeIterator& it1,const InOrderTreeIterator& it2);


        int present_index_=0;
        InOrderTreeView<Type> array_;
    };

    template <class OperatorType>
    bool operator!=(const InOrderTreeIterator<OperatorType>& it1,const InOrderTreeIterator<OperatorType>& it2){
        return it1.present_index_!=it2.present_index_;
    }

    template <class Type>
    std::vector<Type> InOrder(Tree<Type> *tree){
        return tree->InOrder();
    }

    template <class Type>
    class InOrderTreeView{
    public:
        InOrderTreeView()= default;
        InOrderTreeView(Tree<Type> *tree){

            std::copy_n(InOrder(tree).begin(),tree->size_,std::back_inserter(in_order_view_));
        };

        void Implement(Tree<Type> *tree){
            std::copy_n(InOrder(tree).begin(),tree->size_,std::back_inserter(in_order_view_));
        }

        int begin(){return in_order_view_[0];}

        int end(){return in_order_view_[in_order_view_.size()-1];}

        std::vector<int> in_order_view_;
    };
}


#endif //JIMP_EXERCISES_TREEITERATORS_H
