//
// Created by Krzysiek on 05.03.2017.
//

#include "MultiplicationTable.h"
#include <iostream>
using namespace std;

void MultiplicationTable(int tab[][10]){
    for (int x=0; x<10; x++){
        for (int y=0; y<10; y++){

            tab[x][y]=(x+1)*(y+1);
        }

    }
}

void PrintTable(int tab[][10]){
    for (int x=0; x<10; x++){
        for (int y=0; y<10; y++){

            cout << tab[x][y] << "\t";
        }
        cout<<"\n";
    }
}
