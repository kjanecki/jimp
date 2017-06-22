//
// Created by Krzysiek on 02.04.2017.
//

#include "Matrix.h"
#include <iostream>
using ::algebra::Matrix;

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
    Matrix m1{{1.0i, 0., 0.}, {0., 1.0i, 0.}, {0., 0., 1.0i}};
    Matrix m2{{7. + 1.0i, 0., 0.}, {0., 1.0i, 8.}, {15. + 2.0i, 0. + 3.0i, 4. + 1.0i}};
    std::cout << m1.Print() << "\n\n";
    std::cout << m2.Print() << "\n\n\n";
    std::cout << m1.Add(m2).Print() << "\n\n";


    return 0;
}
