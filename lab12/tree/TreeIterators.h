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
    InOrderTreeView<Type> InOrder(Tree<Type> *tree){
        return InOrderTreeView<Type>(tree);
    }

    template <class Type>
    class InOrderTreeView{
    public:
        InOrderTreeView()= default;
        InOrderTreeView(Tree<Type> *tree){
            tree_=tree;
            std::copy_n(tree->InOrder().begin(),tree->size_,std::back_inserter(in_order_view_));
        };

        void Implement(Tree<Type> *tree){
            std::copy_n(tree->InOrder().begin(),tree->size_,std::back_inserter(in_order_view_));
        }

        InOrderTreeIterator<Type> begin(){
            InOrderTreeIterator<Type> t(tree_);
            return t;
        }

        InOrderTreeIterator<Type> end(){
            InOrderTreeIterator<Type> t(tree_);
            t.present_index_=t.array_.in_order_view_.size();
            return t;
        }

        Tree<Type> * tree_= nullptr;
        std::vector<int> in_order_view_;
    };


    template <class Type>
    class PostOrderTreeView;

    template <class Type>
    class PostOrderTreeIterator{
    public:
        PostOrderTreeIterator(Tree<Type> *tree):array_{tree}{
        }

        void operator++(){
            present_index_++;
        }

        Type operator*(){return array_.post_order_view_[present_index_];}

        template <class OperatorType>
        friend bool operator!=(const PostOrderTreeIterator& it1,const PostOrderTreeIterator& it2);

        int present_index_=0;
        PostOrderTreeView<Type> array_;
    };

    template <class OperatorType>
    bool operator!=(const PostOrderTreeIterator<OperatorType>& it1,const PostOrderTreeIterator<OperatorType>& it2){
        return it1.present_index_!=it2.present_index_;
    }

    template <class Type>
    PostOrderTreeView<Type> PostOrder(Tree<Type> *tree){
        return PostOrderTreeView<Type>(tree);
    }

    template <class Type>
    class PostOrderTreeView{
    public:
        PostOrderTreeView()= default;
        PostOrderTreeView(Tree<Type> *tree){
            tree_=tree;
            std::copy_n(tree->PostOrder().begin(),tree->size_,std::back_inserter(post_order_view_));
        };

        void Implement(Tree<Type> *tree){
            std::copy_n(tree->PostOrder().begin(),tree->size_,std::back_inserter(post_order_view_));
        }

        PostOrderTreeIterator<Type> begin(){
            PostOrderTreeIterator<Type> t(tree_);
            return t;
        }

        PostOrderTreeIterator<Type> end(){
            PostOrderTreeIterator<Type> t(tree_);
            t.present_index_=t.array_.post_order_view_.size();
            return t;
        }

        Tree<Type> * tree_= nullptr;
        std::vector<Type> post_order_view_;
    };



    template <class Type>
    class PreOrderTreeView;

    template <class Type>
    class PreOrderTreeIterator{
    public:
        PreOrderTreeIterator(Tree<Type> *tree):array_{tree}{
        }

        void operator++(){
            present_index_++;
        }

        Type operator*(){return array_.pre_order_view_[present_index_];}

        template <class OperatorType>
        friend bool operator!=(const PreOrderTreeIterator& it1,const PreOrderTreeIterator& it2);

        int present_index_=0;
        PreOrderTreeView<Type> array_;
    };

    template <class OperatorType>
    bool operator!=(const PreOrderTreeIterator<OperatorType>& it1,const PreOrderTreeIterator<OperatorType>& it2){
        return it1.present_index_!=it2.present_index_;
    }

    template <class Type>
    PreOrderTreeView<Type> PreOrder(Tree<Type> *tree){
        return PreOrderTreeView<Type>(tree);
    }

    template <class Type>
    class PreOrderTreeView{
    public:
        PreOrderTreeView()= default;
        PreOrderTreeView(Tree<Type> *tree){
            tree_=tree;
            std::copy_n(tree->PreOrder().begin(),tree->size_,std::back_inserter(pre_order_view_));
        };

        void Implement(Tree<Type> *tree){
            std::copy_n(tree->PreOrder().begin(),tree->size_,std::back_inserter(pre_order_view_));
        }

        PreOrderTreeIterator<Type> begin(){
            PreOrderTreeIterator<Type> t(tree_);
            return t;
        }

        PreOrderTreeIterator<Type> end(){
            PreOrderTreeIterator<Type> t(tree_);
            t.present_index_=t.array_.pre_order_view_.size();
            return t;
        }

        Tree<Type> * tree_= nullptr;
        std::vector<Type> pre_order_view_;
    };


}


#endif //JIMP_EXERCISES_TREEITERATORS_H
