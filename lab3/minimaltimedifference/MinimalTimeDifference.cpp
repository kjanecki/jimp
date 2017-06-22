//
// Created by Krzysiek on 16.03.2017.
//

#include "MinimalTimeDifference.h"
#include <iostream>
#include <cstring>

namespace minimaltimedifference {

    unsigned int ToMinutes(std::string time_HH_MM) {
        std::regex pattern{R"((\d{1,2}):(\d{2}))"};
        unsigned int minutes_after_midnight = 0;

        std::smatch matches;
        if (regex_match(time_HH_MM, matches, pattern)) {
            minutes_after_midnight = 60 * stoi(matches[1]) + stoi(matches[2]);
        }
        return minutes_after_midnight;
    }

    unsigned int MinimalTimeDifference(std::vector<std::string> times) {

        unsigned int t1 = ToMinutes(times[0]), t2 = ToMinutes(times[1]);
        unsigned int d1 = 0, d2 = 0;
        if (times.size() <= 2) {
            if (t2 > t1) {
                d1 = t2 - t1;
                d2 = 1440 - t2 + t1;
                if (d1 < d2) {
                    return d1;
                } else {
                    return d2;
                }
            } else {
                d1 = t1 - t2;
                d2 = 1440 - t1 + t2;
                if (d1 < d2) {
                    return d1;
                } else {
                    return d2;
                }
            }
        }
        else{
            std::vector<unsigned int> v2;
            for (auto n : times){
                v2.emplace_back(ToMinutes(n));
            }
            unsigned int d=0;
            if(v2[0]>v2[1]){
                d=v2[0]-v2[1];
            }
            else{
                d=v2[0]-v2[1];
            }
            for(int i=0;i<v2.size();i++){
                for(int j=0; j<v2.size();j++) {
                    if(i==j)
                        continue;
                    if (v2[i] > v2[j]) {
                        if (v2[i] - v2[j] < d) {
                            d = v2[i] - v2[j];
                        }
                        if (1440 - v2[j] + v2[i] < d) {
                            d = 1440 - v2[i] + v2[j];
                        }
                    } else {
                        if (v2[j] - v2[i] < d) {
                            d = v2[j] - v2[i];
                        }
                        if (1440 - v2[j] + v2[i] < d) {
                            d = 1440 - v2[j] + v2[i];
                        }
                    }
                }
            }
            return d;
        }
    }
}