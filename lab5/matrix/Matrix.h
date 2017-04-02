//
// Created by Krzysiek on 02.04.2017.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <complex>
#include <initializer_list>
#include <vector>
#include <memory>

namespace algebra{

    class Matrix{
    public:
        Matrix(){
            complex_matrix_=new std::complex<double>*;
        }

        Matrix(int rows, int cols);

        Matrix(const std::initializer_list<std::vector<std::complex<double>>> &elements);

        Matrix(const Matrix &matrix);

        Matrix &operator=(const Matrix &matrix);

        std::pair<unsigned long, unsigned long> Size();

        std::string Print(){ return ""; };

    private:
        std::complex<double> **complex_matrix_;
        unsigned long rows;
        unsigned long cols;
    };

}

#endif //JIMP_EXERCISES_MATRIX_H
