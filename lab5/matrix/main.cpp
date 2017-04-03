//
// Created by Krzysiek on 02.04.2017.
//

#include "Matrix.h"
#include <iostream>

int main(){

    /*std::string str2="5.3i7.4";
    std::complex<double> c=algebra::ToComplex(str2);
    std::cout << c << "\n\n";
    std::string str3= algebra::ComplexToString(c);

    std::cout << str3 << "\n";

    std::string str4="abc asdd aasda";
    std::regex pattern{R"((.+?) )"};
    std::smatch matches;
    if(std::regex_search(str4,matches,pattern))
    {
        std::cout << matches[0] << "\n";
    }
*/
    std::string str5="[1.0i2 2.4i5; 12i1, 2i5]";
    algebra::Matrix M{str5};
    algebra::Matrix M2{str5};
    //std::cout << M.complex_matrix_[0][0] << "\n\n";
    std::cout << M.Print() << "\n\n";
    str5="[1.0i2, 12i1; 2.4i5 2i5]";
    std::cout << M.Print() << "\n\n\n";
    std::cout << M.Add(M2).Print() << "\n\n";


    return 0;
}
