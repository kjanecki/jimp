//
// Created by Krzysiek on 25.03.2017.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <experimental/optional>
#include <string>
#include <vector>
#include <map>

namespace nets {

    class JsonValue {
    public:

        JsonValue(int arg);

        JsonValue(double arg);

        JsonValue(bool arg);

        JsonValue(std::string arg);

        JsonValue(std::vector<JsonValue> arg);

        JsonValue(std::map<std::string,JsonValue> arg);

        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;


        std::string ToString() const;

   // private:
        std::string name_;
        int int_value_;
        double double_value_;
        bool boolean_value_;
        std::string value_string_;
        std::vector<JsonValue> value_vector_;
        std::map<std::string,JsonValue> value_map_;
        short type_=1; // int 1, double 2, boolean 3, string 4, vector 5, map 6;
    };

}
#endif //JIMP_EXERCISES_SIMPLEJSON_H
