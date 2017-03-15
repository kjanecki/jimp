//
// Created by Krzysiek on 09.03.2017.
//

#include "Array2d.h"
#include <iostream>
using namespace std;

int **NewArray2D(int n_rows, int n_columns){
    if(n_rows<=0 or n_columns<=0){
        return nullptr;
    }
    int **tab=new int *[n_rows];
    int cnt=1;
    for (int i=0;i<n_rows;++i){
        *(tab+i)=new int [n_columns];
    }
    for (int i=0;i<n_rows;++i){
        for (int j=0; j<n_columns;++j){
            *(*(tab+i)+j)=cnt++;
        }
    }
    return tab;
}
int **Array2D(int n_rows, int n_columns){
    return NewArray2D(n_rows,n_columns);
}
void DeleteArray2D(int **array, int n_rows, int n_columns){
    for (int i=0;i<n_rows;++i){
        delete *(array+i);
    }
    delete array;
}