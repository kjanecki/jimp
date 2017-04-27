//
// Created by Krzysiek on 26.04.2017.
//

#include "Pesel.h"

namespace academia{

    void Pesel::ValidatePESEL(const std::string &str){
        if(str.size()!=11){
            throw InvalidPeselLength{"Invalid PESEL("+str+") length: "+(std::to_string(str.size())),int(str.size())};
        }
        for(int i=0; i<str.size();++i){
            if(str[i]<'0' or str[i]>'9'){
                throw InvalidPeselCharacter{"Invalid PESEL("+str+") character set"};
            }
        }

        //9×a + 7×b + 3×c + 1×d + 9×e + 7×f + 3×g + 1×h + 9×i + 7×j

        int tab[]={9,7,3,1,9,7,3,1,9,7};
        int sum=0;
        for(int i=0; i<str.size()-1;++i){
            sum+=tab[i]*((int)str[i]-48);
        }
        sum = sum%10;
        if(sum!=((int)str[str.size()-1]-48)){
            throw InvalidPeselChecksum{"Invalid PESEL("+str+") checksum: "+(std::to_string(sum)),sum};
        }
    };


}