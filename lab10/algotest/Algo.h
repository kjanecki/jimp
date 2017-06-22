//
// Created by Krzysiek on 11.05.2017.
//

#ifndef JIMP_EXERCISES_ALGO_H
#define JIMP_EXERCISES_ALGO_H

#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <vector>

namespace algo {
    std::set<std::string> Keys(const std::map<std::string, int> &m);
    std::vector<int> Values(const std::map<std::string, int> &m);
    void CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out);
    bool Contains(const std::vector<int> &v, int element);
}

#endif //JIMP_EXERCISES_ALGO_H
