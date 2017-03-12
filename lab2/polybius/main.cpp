//
// Created by Krzysiek on 12.03.2017.
//

#include "Polybius.h"
#include <fstream>
//#include <iostream>
using namespace std;

int main(int argc, char *argv[]){

    if(argc!=4){
        cout<< "Error: niepoprawna liczba argumentow\n";
        return 1;
    }

    string str;
    ifstream file_in(*(argv+1));
    ofstream file_out(*(argv+2));

    if(*(*(argv+3))=='1') {
        cout << *(argv+1);
        while (file_in >> str) {
            cout << PolybiusDecrypt(str);
            file_out << PolybiusCrypt(str);
        }

    }

    else if(*(*(argv+3))=='0') {
        while (file_in >> str) {
            cout << PolybiusDecrypt(str);
            file_out << PolybiusDecrypt(str);
        }
    }

    file_in.close();
    file_out.close();
    return 0;
}