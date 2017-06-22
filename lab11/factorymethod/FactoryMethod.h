//
// Created by Krzysiek on 18.05.2017.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H

#include <iostream>
#include <vector>

namespace factoryMethod{

    template <class T>
    T Create(){
        return T();
    }

    class MyType{
    public:
        std::string SayHello(){
            return "hello";
        }
    };

    template <class Sum>
    Sum Summary(Sum a, Sum b){
        return a+b;
    }

    template <class Temp>
    class Repository{
    public:
        Repository(){
            current_id_=0;
        }
        int Size(){return arr_.size();};
        Temp operator[](int index){

            return arr_[index];
        }
        auto NextId(){return ++current_id_;}
        void Insert(Temp t){arr_.push_back(t);}
    private:
        std::vector<Temp> arr_;
        int current_id_;
    };
}

#endif //JIMP_EXERCISES_FACTORYMETHOD_H
