//
// Created by Krzysiek on 02.04.2017.
//

#include "Matrix.h"

namespace algebra {
    Matrix::Matrix(int rows, int cols) {
        this->rows = rows;
        this->cols = cols;
        complex_matrix_ = new std::complex<double> *[this->rows];
        for (int i = 0; i < this->rows; ++i) {
            *(complex_matrix_ + i) = new std::complex<double>[this->cols];
        }
    };


    Matrix::Matrix(const std::initializer_list<std::vector<std::complex<double>>> &elements) {
        this->rows = elements.size();
        this->cols = cols = elements.begin()->size();

        complex_matrix_ = new std::complex<double> *[this->rows];
        for (int i = 0; i < this->rows; ++i) {
            *(complex_matrix_ + i) = new std::complex<double>[this->cols];
        }
        int i = 0;
        for (auto it : elements) {
            auto it2 = it.begin();
            for (int j = 0; j < this->cols; ++j)
                *(*(complex_matrix_ + i) + j) = *(it2 + j);
            ++i;
        }
    };

    std::pair<unsigned long, unsigned long> Matrix::Size() {
        return {this->rows,this->cols};
    }

    Matrix::Matrix(const Matrix &matrix){
        this->rows=matrix.rows;
        this->cols=matrix.cols;
        complex_matrix_=new std::complex<double>*[this->rows];
        for(int i=0;i<this->rows;++i){
            *(complex_matrix_+i)=new std::complex<double>[this->cols];
        }
        for(int i=0;i<this->rows;++i){
            for(int j=0; j<this->cols;++j){
                *(*(this->complex_matrix_+i)+j)=*(*(matrix.complex_matrix_+i)+j);
            }
        }
    };

    Matrix &Matrix::operator=(const Matrix &matrix){
        if(this == &matrix){
            return *this;
        }

        for(int i=0;i<this->rows;++i){
            delete *(this->complex_matrix_+i);
        }
        delete this->complex_matrix_;

        this->rows=matrix.rows;
        this->cols=matrix.cols;
        complex_matrix_=new std::complex<double>*[this->rows];
        for(int i=0;i<this->rows;++i){
            *(complex_matrix_+i)=new std::complex<double>[this->cols];
        }
        for(int i=0;i<this->rows;++i){
            for(int j=0; j<this->cols;++j){
                *(*(this->complex_matrix_+i)+j)=*(*(matrix.complex_matrix_+i)+j);
            }
        }
        return *this;
    };

}