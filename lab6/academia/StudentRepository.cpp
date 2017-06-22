//
// Created by Krzysiek on 05.04.2017.
//

#include "StudentRepository.h"
#include <regex>
#include <string>

namespace academia{

    std::istream &operator>>(std::istream &is,StudyYear& year){
        int value;
        auto *pis=&is;
        (*pis)>>value;
        year.present_year_=value;
    };

    std::ostream &operator<<(std::ostream &os,StudyYear& year){
        auto *pos=&os;
        (*pos)<<year.present_year_;
    };

    std::istream &operator>>(std::istream &is,Student& st){
        //regex pattern {"Student {id: \"(\\d+)\", first_name: \"(\\w+)\", last_name: \"(\\w+)\", program: \"(\\w+)\", year: (\\d)}"};
        std::string str;
        char c;
        int field=0;
        //if(std::regex_match(str,matches,pattern)){
        while(is>>c){
            if(c=='\"') {
                is>>str;
                str.pop_back();
                str.pop_back();
                switch(field){
                    case 0:
                        st.id_=str;
                        field++;
                        break;
                    case 1:
                        st.first_name_=str;
                        field++;
                        break;
                    case 2:
                        st.last_name_=str;
                        field++;
                        break;
                    case 3:
                        st.program_=str;
                        field++;
                        break;
                    default:
                        break;
                }
                if(c>=48 and c<=48+10){
                    StudyYear year((int)c-48);
                    st.year_=year;
                }
            }
        }
    };
}