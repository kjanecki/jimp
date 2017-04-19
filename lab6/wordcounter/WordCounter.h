//
// Created by Krzysiek on 18.04.2017.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <iostream>
#include <map>
#include <initializer_list>
#include <memory>
#include <fstream>
#include <set>

namespace datastructures{

    class Counts{
    public:

        Counts(): value_(1){};

        Counts(int val): value_(val){};

        Counts &operator++();

        int GetVal(){
            return value_;
        }

        friend bool operator>(Counts obj1,Counts obj2);

        friend bool operator<(Counts obj1,Counts obj2);

        friend bool operator==(Counts obj1,Counts obj2);

        friend const Counts &operator+=(unsigned long &val,const Counts &add);

    private:
        int value_;
    };

    class Word{
    public:
        Word(std::string str): word_(str){};

        friend bool operator==(const Word &obj1,const Word &obj2);

        friend bool operator>(const Word &obj1,const Word &obj2);

        friend bool operator<(const Word &obj1,const Word &obj2);

    private:
        std::string word_;
    };

    class WordCounter{
    public:
        WordCounter(){};

        WordCounter(const std::initializer_list<Word> &init_list);

        unsigned long DistinctWords();

        unsigned long TotalWords();

        static const std::map<Word,Counts> &FromInputStream(std::ifstream *is);

        WordCounter(const std::map<Word,Counts> &count);

        std::set<Word> Words();

        int operator[](std::string str);

    private:
        std::map<Word,Counts> counter_;
    };


    bool operator==(const Word &obj1,const Word &obj2);

    bool operator>(const Word &obj1,const Word &obj2);

    bool operator<(const Word &obj1,const Word &obj2);

    const Counts &operator+=(unsigned long &val,const Counts &add);

    bool operator>(Counts obj1,Counts obj2);

    bool operator<(Counts obj1,Counts obj2);

    bool operator==(Counts obj1,Counts obj2);


}


#endif //JIMP_EXERCISES_WORDCOUNTER_H
