//
// Created by Krzysiek on 18.04.2017.
//

#include "WordCounter.h"


namespace datastructures{

    Counts &Counts::operator++(){
        ++value_;
        return *this;
    }

    const Counts &operator+=(unsigned long &val,const Counts &add){
        val+=add.value_;
        return add;
    };

    WordCounter::WordCounter(const std::initializer_list<Word> &init_list) {
        auto *pt=init_list.begin();
        while(pt!=init_list.end()){
            auto it=counter_.find(*pt);
            if(it==counter_.end()){
                Counts c;
                std::pair<Word,Counts> p{*pt,c};
                counter_.insert(it,p);
            }
            else{
                ++it->second;
            }
            ++pt;
        }
    }



    unsigned long WordCounter::DistinctWords(){
        return counter_.size();
    };

    unsigned long WordCounter::TotalWords(){
        unsigned long cnt=0;
        for(auto it : counter_){
            cnt+=it.second.GetVal();
        }
        return cnt;
    };


    bool operator==(const Word &obj1,const Word &obj2){
        return obj1.word_==obj2.word_;
    }

    bool operator>(const Word &obj1,const Word &obj2){
        return obj1.word_>obj2.word_;
    }

    bool operator<(const Word &obj1,const Word &obj2){
        return obj1.word_<obj2.word_;
    }

    bool operator>(Counts obj1,Counts obj2){
        return obj1.value_>obj2.value_;
    }

    bool operator<(Counts obj1,Counts obj2){
        return obj1.value_<obj2.value_;
    }

    bool operator==(Counts obj1,Counts obj2){
        return obj1.value_==obj2.value_;
    }


    const std::map<Word,Counts> &WordCounter::FromInputStream(std::ifstream *is){
        std::map<Word,Counts> counter;
        char c;
        std::string str="";
        while((*is) >> c){
            if((c>=65 && c<=90)or(c>=97 && c<=122)){
                while((c>=65 && c<=90)or(c>=97 && c<=122)){
                    str+=c;
                    (*is)>>c;
                }
                auto it=counter.find(str);
                if(it==counter.end()){
                    ++it->second;
                }
                else{
                    Word w{str};
                    Counts c2;
                    std::pair<Word,Counts> p{w,c2};
                    counter.insert(it,p);
                }
                str="";
            }
        }
        return counter;
    }

    WordCounter::WordCounter(const std::map<Word,Counts> &count){
        counter_=count;
    }

    int WordCounter::operator[](std::string str){
        auto it=counter_.find(Word(str));
        if(it==counter_.end()){
            return 0;
        }
        else{
            return it->second.GetVal();
        }
    }

    std::set<Word> WordCounter::Words(){
        std::set<Word> s;
        for(auto it : counter_){
            s.emplace(it.first);
        }
        return s;
    };

}