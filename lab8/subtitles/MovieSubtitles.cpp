//
// Created by Krzysiek on 01.05.2017.
//

#include "MovieSubtitles.h"

namespace moviesubs{

    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay,int fps, std::stringstream *in,std::stringstream *out){

        if(fps<0){
            throw std::invalid_argument("fps");
        }
        std::string str;
        std::regex pattern {R"(\{(\d+)\}\{(\d+)\}(.*))"};
        std::smatch matches;
        int cnt=0;
        while(getline(*in,str,'\n')){
            ++cnt;
            if(std::regex_search(str, matches, pattern)) {
                int st = std::stoi(matches[1]) + (delay * fps / 1000);
                int en = std::stoi(matches[2]) + (delay * fps / 1000);
                if(en<st){
                    throw SubtitleEndBeforeStart(str,cnt);
                }
                if(st<0){
                    throw NegativeFrameAfterShift(str);
                }
                (*out) << "{" << st << "}";
                (*out) << "{" << en << "}";
                (*out) << matches[3] << "\n";
            }
            else{
                throw InvalidSubtitleLineFormat("Format");
            }
        }
    }

    void SubRipSubtitles::ShiftAllSubtitlesBy(int delay,int fps, std::stringstream *in,std::stringstream *out){

        if(fps<0){
            throw std::invalid_argument("fps");
        }

        std::string str;
        std::regex pattern {R"((\d{2}):(\d{2}):(\d{2}),(\d{3}) --> (\d{2}):(\d{2}):(\d{2}),(\d{3}))"};
        std::smatch matches;
        int cnt=0;
        while(getline(*in,str,'\n')){
            cnt++;
            if(cnt!=std::stoi(str)){
                throw OutOfOrderFrames(str);
            }

            (*out)<<str <<'\n';


            getline(*in,str,'\n');

            if(std::regex_search(str,matches,pattern)){
                ValidateTimes(matches,str,cnt,delay);
                (*out)<<matches[1] << ":" << matches[2] << ":";
                int ms=std::stoi(matches[4])+delay;
                if(ms<0){
                    throw NegativeFrameAfterShift(str);
                }
                if(ms<1000){
                    std::string str2=std::to_string(ms);
                    while(str2.size()<3){
                        str2='0'+str2;
                    }
                    (*out)<<matches[3] << "," << str2 << " --> ";
                }
                else{
                    int sec=std::stoi(matches[3])+ms/1000;
                    ms%=1000;
                    std::string str2=std::to_string(ms);
                    while(str2.size()<3){
                        str2='0'+str2;
                    }
                    std::string str3=std::to_string(sec);
                    while(str3.size()<2){
                        str3='0'+str3;
                    }
                    (*out)<< str3 << "," << str2 << " --> ";
                }

                (*out)<<matches[5] << ":" << matches[6] << ":";
                ms=std::stoi(matches[8])+delay;
                if(ms<1000){
                    std::string str2=std::to_string(ms);
                    while(str2.size()<3){
                        str2='0'+str2;
                    }
                    (*out)<<matches[7] << "," << str2 << " --> ";
                }
                else{
                    int sec=std::stoi(matches[7])+ms/1000;
                    ms%=1000;
                    std::string str2=std::to_string(ms);
                    while(str2.size()<3){
                        str2='0'+str2;
                    }
                    std::string str3=std::to_string(sec);
                    while(str3.size()<2){
                        str3='0'+str3;
                    }
                    (*out)<< str3 << "," << str2 << '\n';

                }
            }
            else{
                std::regex patt {R"([a-zA-Z]+)"};
                std::smatch match1;
                if(std::regex_search(str,match1,patt)){
                    throw MissingTimeSpecification(str);
                }
                else {
                    throw InvalidSubtitleLineFormat(str);
                }
            }
            while(str!=""){
                getline(*in,str,'\n');
                (*out)<<str;
                if(!in->eof()){
                    (*out)<<"\n";
                }
            }

        }
    };
    void SubRipSubtitles::ValidateTimes(std::smatch m,std::string str, int cnt,int delay){
        long start_time=std::stoi(m[1])*60*60*1000+std::stoi(m[2])*60*1000+std::stoi(m[3])*1000+std::stoi(m[4]);
        long end_time=std::stoi(m[5])*60*60*1000+std::stoi(m[6])*60*1000+std::stoi(m[7])*1000+std::stoi(m[8]);
        if(end_time<start_time) {
            throw SubtitleEndBeforeStart(str, cnt);
        }
        if(start_time+delay<0 or end_time+delay<0){
            throw NegativeFrameAfterShift(str);
        }
    }
}