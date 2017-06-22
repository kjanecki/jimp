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

    void CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out){
        std::copy_n(v.begin(),n_elements,std::back_inserter(*out));
    }

    bool Contains(const std::vector<int> &v, int element){
        return std::find(v.begin(),v.end(),element) != v.end();
    }
}