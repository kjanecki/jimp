//
// Created by Krzysiek on 04.05.2017.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <iostream>
#include <functional>
#include <vector>

namespace academia{

    class Serializer;

    class Serializable{
    public:
        virtual void Serialize(Serializer *)=0;

    };

    class Serializer{
    public:
        Serializer(std::ostream *out):out_(out){};

        virtual void IntegerField(const std::string &field_name, int value) =0;
        virtual void DoubleField(const std::string &field_name, double value) =0;
        virtual void StringField(const std::string &field_name, const std::string &value) =0;
        virtual void BooleanField(const std::string &field_name, bool value) =0;
        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value) =0;
        virtual void ArrayField(const std::string &field_name,
                               const std::vector<std::reference_wrapper<const academia::Serializable>> &value) =0;
        virtual void Header(const std::string &object_name) =0;
        virtual void Footer(const std::string &object_name) =0;

    protected:
        std::ostream *out_;
    };

    class Room: public Serializable{
    public:
        enum class Type{
            COMPUTER_LAB,
            CLASSROOM,
            LECTURE_HALL
        };

        Room(int id, const std::string &name, Room::Type type);

        void Serialize(Serializer *serializer) override;

    private:
        std::string TypeToString(const Type &type){
            switch (type){
                case Type::CLASSROOM:
                    return "CLASSROOM";
                case Type::LECTURE_HALL:
                    return "LECTURE_HALL";
                case Type::COMPUTER_LAB:
                    return "COMPUTER_LAB";

            }
        }

        std::string name_;
        int id_;
        Type type_;
    };

    class Building: public Serializable{
    public:
        Building(int id, const std::string &name, const std::vector<Room> &rooms);

    private:
        std::string name_;
        int id_;
        std::vector<Room> rooms_;
    };
}


#endif //JIMP_EXERCISES_SERIALIZATION_H
