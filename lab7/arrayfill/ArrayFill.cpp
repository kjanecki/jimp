//
// Created by Krzysiek on 20.04.2017.
//

#include "ArrayFill.h"

namespace arrays{

    void FillArray(int size,Filler &f, std::vector<int> *vs){
        if(vs->size()!=0){
            vs->clear();
        }
        for(int i=0; i<size; ++i){
            vs->push_back(f.fill(i));
        }
    }

    int IncrementalFill::fill(int index){
        return value_a_*index+value_b_;
    }

    int SquaredFill::fill(int index){
        return a_param_*index*index+b_param_*index+c_param_;
    }

    int UniformFill::fill(int index){
        return value_;
    }

    int RandomFill::fill(int index=0){

    }

}