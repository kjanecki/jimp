//
// Created by Krzysiek on 18.05.2017.
//

#include <FactoryMethod.h>


int main(){
    double d1=2.5,d2=2.7;
    factoryMethod::Repository<double> repo;
    repo.Insert(d1);
    std::cout << repo.NextId() << "\n";
    repo.Insert(d2);
    std::cout << repo.NextId() << "\n";

    return 0;
}