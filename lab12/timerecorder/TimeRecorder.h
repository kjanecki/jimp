//
// Created by Krzysiek on 05.06.2017.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H


#include <map>
#include <chrono>

namespace profiling {
    template<typename Type>
    auto TimeRecorder(Type obj) {
        typedef std::chrono::high_resolution_clock clock;
        typedef std::chrono::duration<double, std::milli> duration;
        static clock::time_point t1 = clock::now();
        auto result = obj();
        duration difference = clock::now() - t1;
        return std::pair<decltype(result), double>(result, difference.count());
    };
}

#endif //JIMP_EXERCISES_TIMERECORDER_H
