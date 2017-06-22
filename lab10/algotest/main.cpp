//
// Created by Krzysiek on 11.05.2017.
//

#include <Algo.h>

int main(){
    std::map<std::string,int> m{{"a",1},{"b",2},{"c",3}};
    std::set<std::string> s=algo::Keys(m);
    std::cout << *s.begin() << " " << *(++s.begin());

}