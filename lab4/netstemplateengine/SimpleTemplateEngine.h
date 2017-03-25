//
// Created by Krzysiek on 25.03.2017.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H

#include <string>
#include <unordered_map>

namespace nets{

    class View{
    public:

        View(std::string arg):template_(arg){};

        std::string Render(const std::unordered_map <std::string, std::string> &model) const;

        std::string template_;
    };

}


#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
