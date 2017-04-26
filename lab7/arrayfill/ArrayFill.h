//
// Created by Krzysiek on 20.04.2017.
//

#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H

#include <vector>
#include <random>

namespace arrays{

    class Filler{
    public:
        virtual int fill(int index) =0;
    };

    class IncrementalFill: public Filler{
    public:
        IncrementalFill(int val):value_b_(val),value_a_(1){};

        IncrementalFill(int val_b,int val_a):value_b_(val_b),value_a_(val_a){};

        int fill(int index) override;
    private:
        int value_a_;
        int value_b_;
    };

    class SquaredFill: public Filler{
    public:
        SquaredFill():a_param_(1){};

        SquaredFill(int a):a_param_(a){};

        SquaredFill(int a,int b):a_param_(a),c_param_(b){};

        SquaredFill(int a,int b,int c):a_param_(a),b_param_(b),c_param_(c){};

        int fill(int index) override;

    private:
        int a_param_=0;
        int b_param_=0;
        int c_param_=0;
    };

    class UniformFill: public Filler{
    public:
        UniformFill():value_(0){};

        UniformFill(int param):value_(param){};

        int fill(int index) override;
    private:
        int value_;
    };

    class RandomFill:public Filler{
    public:
        RandomFill(std::unique_ptr<std::default_random_engine> gen,std::unique_ptr<std::uniform_int_distribution> distr):
                gen_(move(gen)), distr_(move(distr)){};

        int fill(int index=0) override;

    private:
        std::unique_ptr<std::default_random_engine> gen_;
        std::unique_ptr<std::uniform_int_distribution> distr_;
    };

    void FillArray(int size,Filler &f, std::vector<int> *vs);

}


#endif //JIMP_EXERCISES_ARRAYFILL_H
