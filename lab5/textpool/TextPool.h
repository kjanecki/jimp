//
// Created by Krzysiek on 02.04.2017.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H

#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>
#include <cstring>
#include <algorithm>


namespace pool{

    class TextPool{
    public:
        TextPool() {
            //StringSet_= new std::set<std::experimental::string_view>;
        }

        TextPool(const std::initializer_list<std::experimental::string_view> &elements);

        TextPool(const TextPool &text) = delete;

        TextPool &operator=(const TextPool &text) = delete;

        TextPool( TextPool &&text);

        TextPool &operator=(TextPool &&text);

        ~TextPool();

        std::experimental::string_view Intern(const std::string &str);

        size_t StoredStringCount() const;

    private:
        std::set<std::experimental::string_view> StringSet_;
    };
}


#endif //JIMP_EXERCISES_TEXTPOOL_H
