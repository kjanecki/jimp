//
// Created by Krzysiek on 02.04.2017.
//

#include "TextPool.h"

namespace pool{


    TextPool::TextPool(const std::initializer_list<std::experimental::string_view> &elements){
        for(auto it : elements){
            StringSet_.insert(it);
           //auto it2 = StringSet_->insert(it);
        }
    };

    TextPool::TextPool(TextPool &&text){
        TextPool::StringSet_.clear();
        auto temp=text.StringSet_;
        text.StringSet_=StringSet_;
        StringSet_=temp;
    };

    TextPool &TextPool::operator=(TextPool &&text){
        if(this == &text){
            return *this;
        }
        TextPool::StringSet_.clear();
        auto temp=text.StringSet_;
        text.StringSet_=StringSet_;
        StringSet_=temp;
        return *this;
    };

    TextPool::~TextPool(){
        StringSet_.clear();
    };

    std::experimental::string_view TextPool::Intern(const std::string &str){
        auto it=TextPool::StringSet_.find(str);
        if(it!=TextPool::StringSet_.end()){
            return it->begin();
        }
        else{
            auto it2=TextPool::StringSet_.emplace(str);
            return it2.first->begin();
        }
    };

    size_t TextPool::StoredStringCount() const{
        return TextPool::StringSet_.size();
    };
};