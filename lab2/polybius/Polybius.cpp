//
// Created by Krzysiek on 12.03.2017.
//

#include "Polybius.h"
//#include <string>

std::string CryptCharacter (char character){
    int c=int(character);
    std::string value="  ";
    if(c>=97){
        c-=96;
    }
    else{
        c-=64;
    }

    if(c>=10){
        c--;
    }

    value[0]=char((c-1)/5+1+48);
    if(c%5==0){
        value[1]='5';
    }
    else{
        value[1]=char(c%5+48);
    }

    return value;
}

char DecryptCharacter(int val){
    char character;
    int temp=val/10-1;
    if(val>24){
        temp=temp*5+(val%10);
        character=char(temp+97);
    }
    else{
        temp=temp*5+(val%10);
        character=char(temp+96);
    }
    return character;
}

std::string PolybiusCrypt(std::string message){
    std::string en_message="";
    for(int i=0; i<message.size();i++){
        if(int(message[i])!=32)
            en_message=en_message+CryptCharacter(message[i]);
    }
    return en_message;
}
std::string PolybiusDecrypt(std::string crypted){
    std::string de_message="";
    for(int i=0; i<crypted.size(); i+=2){
        int k=(int(crypted[i])-48)*10;
        k+=(int(crypted[i+1])-48);
        de_message=de_message+DecryptCharacter(k);

    }
    return de_message;
}