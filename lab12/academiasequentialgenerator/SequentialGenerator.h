//
// Created by Pałeł on 2017-06-05.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H


template<class TestId, class BaseValue>
class SequentialIdGenerator {
public:
    SequentialIdGenerator(){};
    SequentialIdGenerator(const BaseValue &generator):id_(generator){};
    int NextValue(){
        BaseValue val = id_;
        ++id_;
        return  int(val);
    }


private:
    BaseValue id_=0;

};

#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H
