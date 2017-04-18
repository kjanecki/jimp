//
// Created by Krzysiek on 05.04.2017.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H

#include <iostream>

namespace academia{

    class StudyYear{
    public:

        StudyYear():present_year_(1){};

        StudyYear(int year):present_year_(year){};

        StudyYear &operator++(){
            ++present_year_;
            return *this;
        }

        StudyYear &operator--(){
            --present_year_;
            return *this;
        }

        int GetYear()const{
            return present_year_;
        }
        void SetYear(int y){
            present_year_=y;
        }

        friend std::istream &operator>>(std::istream &is,StudyYear& year);

        friend std::ostream &operator<<(std::ostream &os,StudyYear& year);

    private:
        int present_year_;
    };

    class Student{
    public:
        friend std::istream &operator>>(std::istream &is,Student& st);
    private:
        std::string id_;
        std::string first_name_;
        std::string last_name_;
        std::string program_;
        StudyYear year_;
    };

    std::istream &operator>>(std::istream &is,StudyYear& year);

    std::ostream &operator>>(std::ostream &os,StudyYear& year);

    std::istream &operator>>(std::istream &is,Student& st);
}


#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
