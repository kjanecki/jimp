//
// Created by Krzysiek on 01.05.2017.
//

#include "MovieSubtitles.h"
#include <iostream>

using namespace moviesubs;

int main(){

    MicroDvdSubtitles subs;
    std::stringstream in {"{0}{250}TEXT TEXT\n{260}{300}NEWLINE\n"};
    std::stringstream out;
    subs.ShiftAllSubtitlesBy(1400, 10, &in, &out);


    return 0;
}