//
// Created by Krzysiek on 21.03.2017.
//

#ifndef JIMP_EXERCISES_CCOUNTER_H
#define JIMP_EXERCISES_CCOUNTER_H

#include <string>
#include <memory>
#include <map>
using std::map;
using std::string;

namespace ccounter{

    struct Counter{
        map<string, int> key_counter;
    };


    std::unique_ptr<Counter> Init();

    void Inc(std::string key, std::unique_ptr<Counter>* counter);

    int Counts(const std::unique_ptr<Counter> &counter, std::string key);

    void SetCountsTo(std::string key, int value, std::unique_ptr<Counter> *counter);
}


#endif //JIMP_EXERCISES_CCOUNTER_H
