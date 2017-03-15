//
// Created by Krzysiek on 15.03.2017.
//

#include "XorCypherBreaker.h"
#include <algorithm>
using std::find;
using std::vector;
using std::string;



std::string XorCypherBreaker(const std::vector<char> &cryptogram,
                             int key_length,
                             const std::vector<std::string> &dictionary){
    string A="aaa";
    for(char i=97;i<=122;i++){
        A[0]=i;
        for(char j=97;j<=122;j++){
            A[1]=j;
            for(char k=97;k<=122;k++){
                A[2]=k;
                if(Guess(cryptogram, key_length, dictionary, A)){
                    return A;
                }
            }
        }
    }
    return "";
}


bool Guess(const std::vector<char> &cryptogram,
           int key_length,
           const std::vector<std::string> &dictionary,std::string key){
    std::vector<std::string> v2;
    std::string temp="";
    for(int i=0; i<cryptogram.size();++i){
        int n=cryptogram[i]^key[i%key_length];
        if(n!=32){
            temp=temp+char(n);
        }
        else{
            v2.push_back(temp);
            temp="";
        }
    }
    int cnt=0;
    for (int i=0; i<v2.size();i++){
        if (find(dictionary.begin(),dictionary.end(),v2[i]) != dictionary.end()){
            cnt++;
        }
    }
    while(v2.size()!=0){
        v2.pop_back();
    }

    if(cnt>10){
        return true;
    }
    else{
        return false;
    }
}


