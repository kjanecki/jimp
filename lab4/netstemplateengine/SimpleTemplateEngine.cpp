//
// Created by Krzysiek on 25.03.2017.
//

#include "SimpleTemplateEngine.h"
#include <iostream>
using ::std::string;

namespace nets{


    std::string View::Render(const std::unordered_map <std::string, std::string> &model) const{

        std::string output;
        for(int i=0;i<template_.size();++i){
            std::string str="";
            if(template_[i]!='{'){
                output=output+template_[i];
            }
            else{
                if(template_[i+1]=='{'){
                    if(template_[i+2]=='{') {
                        output = output + template_[i];
                        continue;
                    }
                    else{
                        int j=i+2;
                        while(template_[j]!='}'){
                            str=str+template_[j];
                            ++j;
                        }
                        ++j;
                        if(template_[j]!='}'){
                            output=output+template_[i];
                        }
                        else{
                            auto word=model.find(str);
                            if(word!=model.end()){
                                output=output+word->second;
                                i=j;
                            }
                            else{
                                i=j;
                            }
                        }
                    }
                }
                else{
                    output=output+template_[i];
                }
            }

        }
        return output;
    }


}