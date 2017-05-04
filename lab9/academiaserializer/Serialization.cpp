//
// Created by Krzysiek on 04.05.2017.
//

#include "Serialization.h"

namespace academia{


    Room::Room(int id, const std::string &name, Room::Type type) : name_(name), id_(id), type_(type) {}

    void Room::Serialize(Serializer *serializer) {
        serializer->Header("room");
        serializer->IntegerField("id_",id_);
        serializer->StringField("name_",name_);
        serializer->StringField("Type",TypeToString(type_));
        serializer->Footer("room");
    }

    Building::Building(int id, const std::string &name, const std::vector<Room> &rooms)
            :  name_(name), id_(id), rooms_(rooms) {}

}