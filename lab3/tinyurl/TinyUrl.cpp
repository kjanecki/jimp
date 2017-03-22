//
// Created by Krzysiek on 20.03.2017.
//

#include "TinyUrl.h"
namespace tinyurl {

    std::unique_ptr<TinyUrlCodec> Init(){
        std::unique_ptr<TinyUrlCodec> u_ptr=std::make_unique<TinyUrlCodec>();
        std::array<char,6> arr{'0','0','0','0','0','0'};
        u_ptr->present_hash=arr;
        return u_ptr;
    };

    void NextHash(std::array<char, 6> *state){
        char *temp=state->end()-1;

        int add=1;
        do{
            *temp+=add;
            add=0;
            if(*temp=='9'+1){
                *temp='A';
            }
            else if(*temp=='Z'+1){
                *temp='a';

            }
            else if(*temp=='z'+1){
                *temp='0';
                add=1;
            }

            temp=temp-1;
        }while(add!=0);

    }

    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec){
        std::string str="";
        for(int i=0;i<6;i++){
            str=str+(*codec)->present_hash.begin()[i];
        }
        (*codec)->code_map.emplace(str,url);
        NextHash(&(*codec)->present_hash);
        return str;
    }

    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash){
        auto i=codec->code_map.find(hash);
        return i->second;
    }

}