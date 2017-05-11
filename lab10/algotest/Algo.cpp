//
// Created by Krzysiek on 11.05.2017.
//

#include "Algo.h"

namespace algo {
    std::set<std::string> Keys(const std::map<std::string, int> &m) {
        std::set<std::string> s;
        std::transform(m.begin(), m.end(), std::inserter(s, s.begin()), [](const auto &it) { return it.first; });
        return s;
    }

    std::vector<int> Values(const std::map<std::string, int> &m) {
        std::vector<int> s;
        std::transform(m.begin(), m.end(), std::back_inserter(s), [](const auto &it) { return it.second; });
        return s;
    }
}