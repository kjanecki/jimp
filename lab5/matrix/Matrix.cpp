//
// Created by Krzysiek on 02.04.2017.
//

#include "Matrix.h"
using ::std::vector;

namespace algebra {
    Matrix::Matrix(unsigned long rows, unsigned long cols) {
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
            int j=0;
            for(auto it2 : it) {
                *(*(complex_matrix_ + i) + j) = it2;
                ++j;
            }
            ++i;
        }
    };

    Matrix::Matrix(std::string text){
        vector<std::string> v;
        int rows_cnt=0;
        int cols_cnt=0;
        std::string temp="";
        bool cols_counted=false;
        for(int i=1; i<text.size();++i){
            if(!cols_counted and text[i]==' '){
                cols_cnt++;
            }
            if(text[i]==';' or i==text.size()-1){
                if(!cols_counted){
                    cols_counted=true;
                    cols_cnt++;
                }
                rows_cnt++;
                v.emplace_back(temp);
                temp="";
                i++;
            }
            else{
                temp=temp+text[i];
            }
        }
        auto asd = v[0];
        complex_matrix_=new std::complex<double> *[rows_cnt];
        for(int i=0; i<rows_cnt;++i){
            *(complex_matrix_+i)=new std::complex<double> [cols_cnt];
        }

        for(int i=0; i<rows_cnt;++i){
            std::string temp2="";
            int k=0;
            for(int j=0;j<v[i].size();++j){
                if(v[i][j]==' '){
                    *(*(complex_matrix_+i)+k)=ToComplex(temp2);
                    k++;
                    temp2="";
                }
                else{
                    if(j==v[i].size()-1){
                        temp2 = temp2 + v[i][j];
                        *(*(complex_matrix_+i)+k)=ToComplex(temp2);
                        k++;
                        temp2="";
                    }
                    else {
                        temp2 = temp2 + v[i][j];
                    }
                }
            }
        }
        rows=rows_cnt;
        cols=cols_cnt;
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

    std::string Matrix::Print(){
        std::string str="[";
        for(int i=0; i<rows;++i){
            for(int j=0; j<cols; ++j){
                str=str+ComplexToString(*(*(complex_matrix_+i)+j));
                if(j!=cols-1){
                    str=str+" ";
                }
            }
            if(i!=rows-1)
                str=str+"; ";
        }
        str=str+"]";
        return str;
    };


    Matrix Matrix::Add (const Matrix &m2){
        if(this->rows!=m2.rows or this->cols!=m2.cols){
            return *this;
        }
        else{
            for(int i=0;i<this->rows;++i){
                for(int j=0;j<this->cols;++j){
                    *(*(this->complex_matrix_+i)+j)+=*(*(m2.complex_matrix_+i)+j);
                }
            }
            return *this;
        }
    };

    std::complex<double> ToComplex (std::string str){
        std::complex<double> out;
        std::string temp;
        std::regex pattern{R"((.+)i(.+))"};
        std::smatch matches;
        if(std::regex_search(str,matches,pattern)){
            out.real(std::stod(matches[1]));
            out.imag(std::stod(matches[2]));
            return out;
        }
        else{
            return {};
        }
    }


    std::string ComplexToString (std::complex<double> c){
        std::string out="";
        std::string temp=std::to_string(c.real());
        while(temp[temp.size()-1]=='0')
            temp.pop_back();
        if(temp[temp.size()-1]=='.')
            temp.pop_back();
        out=out+temp+'i';
        temp=std::to_string(c.imag());
        while(temp[temp.size()-1]=='0')
            temp.pop_back();
        if(temp[temp.size()-1]=='.')
            temp.pop_back();
        out=out+temp;
        return out;
    };
}