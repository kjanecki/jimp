//
// Created by Pałeł on 2017-06-05.
//

#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H

#include <string>

namespace academia {
    class TeacherId {
    public:
        TeacherId(const int &id){this->id_=id;};
        operator int()const{return id_;};
    private:
        int id_;

    };

    class Teacher {
    public:
        Teacher(const TeacherId &id, std::string Name, std::string Department): id_(id),name_(Name),department_(Department) {};

        int Id() const { return id_; };
        std::string Name() const { return name_; };
        std::string Department() const { return department_; };

        bool operator==(const Teacher& teacher) const {
            if (id_==teacher.id_ and name_==teacher.name_ and department_==teacher.department_){
                return true;
            }
            else{
                return false;
            }
        }
        bool operator!=(const Teacher& teacher) const {
            if (id_==teacher.id_ and name_==teacher.name_ and department_==teacher.department_){
                return false;
            }
            else{
                return true;
            }
        }

    private:
        TeacherId id_;
        std::string name_;
        std::string department_;
    };

    class TeacherHash{
    public:
        TeacherHash() {}
        size_t operator()(const Teacher &t) const{
            return std::hash<int>{}(t.Id())^std::hash<std::string>{}(t.Name())^std::hash<std::string>{}(t.Department());
        };
    };
}

#endif //JIMP_EXERCISES_TEACHERHASH_H
