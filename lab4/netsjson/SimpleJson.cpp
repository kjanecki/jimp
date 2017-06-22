//
// Created by Krzysiek on 25.03.2017.
//

#include "SimpleJson.h"


namespace nets{

    JsonValue::JsonValue(int arg){
        int_value_=arg;
        type_=1;
    }

    JsonValue::JsonValue(double arg){
        double_value_=arg;
        type_=2;
    }

    JsonValue::JsonValue(bool arg){
        boolean_value_=arg;
        type_=3;
    }

    JsonValue::JsonValue(std::string arg){
        value_string_=arg;
        type_=4;
    }

    JsonValue::JsonValue(std::vector<JsonValue> arg){
        value_vector_=arg;
        type_=5;
    }

    JsonValue::JsonValue(std::map<std::string,JsonValue> arg){
        value_map_=arg;
        type_=6;
    }

    std::string JsonValue::ToString() const{
        std::string str="";
        switch(type_){
            case 1:
                str=std::to_string(int_value_);
                break;
            case 2:
                str=std::to_string(double_value_);
                while(str[str.size()-1]=='0'){
                    str.pop_back();
                }
                break;
            case 3:
                if(boolean_value_==0){
                    str="false";
                }
                else{
                    str="true";
                }
                break;
            case 4:
                str+="\"";
                for (int i=0;i<value_string_.size();++i){
                    if(value_string_[i]=='\"' or value_string_[i]=='\\' or value_string_[i]=='"') {
                        str = str + "\\" + value_string_[i];
                    }
                    else
                        str=str+value_string_[i];
                }
                str+="\"";
                break;
            case 5:
                str=str+"[";
                for (int i=0;i<value_vector_.size();++i){
                    str=str+value_vector_[i].ToString();
                    if(i!=value_vector_.size()-1)
                        str=str+", ";
                }
                str=str+"]";
                break;
            case 6:
                str=str+"{";
                int k=0;
                for (auto n : value_map_){
                    if (k!=0){
                        str=str+", ";
                    }
                    k++;

                    str+="\"";
                    for (int i=0;i<n.first.size();++i){
                        if(n.first[i]=='\"' or n.first[i]=='\\' or n.first[i]=='"') {
                            str = str + "\\"+char(n.first[i]);
                        }
                        else
                            str=str+char(n.first[i]);
                    }
                    str+="\"";


                    str=str+": "+n.second.ToString();

                }
                str=str+"}";
                break;

            default:
                break;
        }
        return str;
    }

    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const{
        auto i=value_map_.find(name);
        if(i!=value_map_.end()){
            return std::experimental::make_optional(i->second);
        }
        else{
            return {};
        }
    }


}