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
        std::string str,temp;
        std::regex pattern {R"((\d*)\n(\d\d:\d\d:\d\d,\d\d\d) --> (\d\d:\d\d:\d\d,\d\d\d)((\n.+)+))"};
        std::regex time_pattern {R"((\d\d):(\d\d):(\d\d),(\d\d\d))"};
        std::smatch matches;
        while(getline(*in,temp,'\n')){
            str+=temp;
            if(temp!=""){
                str+='\n';
                continue;
            }

            if(std::regex_search(str, matches, pattern)) {
                std::smatch matches_start, matches_end;
                std::string time_start = matches[2];
                std::string time_end = matches[3];
                (*out) << matches[1] << "\n";
                for (int i = 2; i <= 3; ++i) {
                    std::string present_str;
                    if(i==2){
                        present_str=time_start;
                    }
                    else{
                        present_str=time_end;
                    }
                    if (std::regex_search(present_str, matches_start, time_pattern)) {
                        int ms = std::stoi(matches_start[4]) + delay;
                        (*out) << matches_start[1] << ';';
                        (*out) << matches_start[2] << ';';
                        if (ms >= 1000) {
                            int part = ms / 1000;
                            ms %= 1000;
                            int sec = std::stoi(matches_start[3]) + part;
                            (*out) << std::to_string(sec) <<',';
                        } else {
                            (*out) << matches_start[3] << ',';
                        }
                        (*out) << std::to_string(ms);
                    }
                    if (i != 3)
                        (*out) << " --> ";
                }
                int i = 0;
                for (auto it : matches) {
                    if (i >= 4) {
                        (*out) << it.first.base() << "\n";

                    }
                    ++i;
                }
            }
            str="";
        }
    };

}