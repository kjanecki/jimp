//
// Created by Krzysiek on 21.03.2017.
//

#include "CCounter.h"

namespace ccounter{

    std::unique_ptr<Counter> Init(){
        std::unique_ptr<Counter> u_ptr= std::make_unique<Counter>();
        return u_ptr;
    }

    void Inc(std::string key, std::unique_ptr<Counter>* counter){
        auto i=(*counter)->key_counter.find(key);
        if(i!=(*counter)->key_counter.end()){
            i->second++;
        }
        else{
            (*counter)->key_counter.emplace(key,1);
        }
    }

    int Counts(const std::unique_ptr<Counter> &counter, std::string key){
        auto i=counter->key_counter.find(key);
        if(i!=counter->key_counter.end()){
            return i->second;
        }
        else{
            return 0;
        }

    }

    void SetCountsTo(std::string key, int value, std::unique_ptr<Counter> *counter){
        auto i=(*counter)->key_counter.find(key);
        if(i!=(*counter)->key_counter.end()){
            i->second=value;
        }
        else{
            (*counter)->key_counter.emplace(key,value);
        }
    }
}