//
// Created by Krzysiek on 26.04.2017.
//

#include "Figure.h"
using ::std::cout;

namespace geometria{

    void Kwadrat::Rysuj() {
        for(int i=0;i<4;++i){
            for(int j=0; j<4;++j){
                cout << "x ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    void Trojkat::Rysuj() {
        for(int i=0;i<4;++i){
            for(int j=0; j<4;++j){
                if(j<=i)
                    cout << "x ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    void Kolo::Rysuj() {
        for(int i=0;i<4;++i){
            for(int j=0; j<4;++j){
                if((i==0 and j==0) or (i==0 and j==3) or (i==3 and j==0) or (i==3 and j==3)){
                    cout << "  ";
                } else {
                    cout << "x ";
                }
            }
            cout << "\n";
        }
        cout << "\n";
    }


}