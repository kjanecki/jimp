//

//

#include "Serialization.h"

namespace academia{


    Room::Room(int id, const std::string &name, Room::Type type) : name_(name), id_(id), type_(type) {}

    void Room::Serialize(Serializer *serializer) const {
        serializer->Header("room");
        serializer->IntegerField("id",id_);
        serializer->Separate();
        serializer->StringField("name",name_);
        serializer->Separate();
        serializer->StringField("type",TypeToString(type_));
        serializer->Footer("room");
    }
    void Building::Serialize(Serializer *serializer)const{

        serializer->Header("building");
        serializer->IntegerField("id",id_);
        serializer->Separate();
        serializer->StringField("name",name_);
        serializer->Separate();
        serializer->Header("rooms");
        for(int i=0; i<rooms_.size();++i){
            rooms_[i].Serialize(serializer);
            if(i!=rooms_.size()-1)
                serializer->Separate();
        }
        serializer->Footer("rooms");
        serializer->Footer("building");

            serializer->Header("building");
            serializer->IntegerField("id",id_);
            serializer->Separate();
            serializer->StringField("name",name_);
            serializer->Separate();
            serializer->Header("rooms");
            for(int i=0; i<rooms_.size();++i){
                rooms_[i].Serialize(serializer);
                if(i!=rooms_.size()-1)
                    serializer->Separate();
            }
            serializer->Footer("rooms");
            serializer->Footer("building");
    }

    Building::Building(int id, const std::string &name, const std::vector<Room> &rooms)
            :  name_(name), id_(id), rooms_(rooms) {}



    BuildingRepository::BuildingRepository(const std::initializer_list<Building> &building){
        for(const auto &n : building){
            Add(n);
        }
    }

    void BuildingRepository::Add(Building building) {
        building_.emplace_back(building);
    }

    BuildingRepository::~BuildingRepository() {}
    void BuildingRepository::StoreAll(Serializer *serializer) const {
        serializer->Header("building_repository");
        std::vector<std::reference_wrapper<const Serializable>> v;
        for(const Building &n : building_){
            v.emplace_back(n);
        }
        serializer->ArrayField("buildings",v);
        serializer->Footer("building_repository");
    }

    int Building::Id(void) const {
        return id_;
    }
    std::experimental::optional<Building> BuildingRepository::operator[](int ind) const {

        for(int i=0; i<building_.size();i++)
        {
            if(building_[i].Id()==ind)
                return std::experimental::make_optional(building_[i]);
        }
        return std::experimental::optional<Building>();
    }
    }