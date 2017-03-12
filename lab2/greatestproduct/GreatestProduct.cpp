//
// Created by Krzysiek on 12.03.2017.
//

#include "GreatestProduct.h"
#include <iostream>
using namespace std;

int GreatestProduct(const std::vector<int> &numbers, int k){
    if(k<=0){
        return -1;
    }
    std::vector<int> positive_max,negative_max,negative_min;
    int result=1;
    for (auto v : numbers){

        if(v>=0) {

            if(positive_max.size()==0){
                positive_max.emplace_back(v);
            }
            else {
                positive_max.emplace_back(v);
                int i=positive_max.size()-2;
                while(v>positive_max[i] and i>=0){
                    positive_max[i+1]=positive_max[i];
                    i-=1;
                }
                if(positive_max[i+1]!=v){
                    positive_max[i+1]=v;
                }

            }
            if(positive_max.size()>k){
                positive_max.pop_back();
            }

        }
        else{

            if(negative_max.size()==0){
                negative_max.emplace_back(v);
                negative_min.emplace_back(v);
            }

            else {
                negative_max.emplace_back(v);
                int i=negative_max.size()-2;
                while(v<negative_max[i] and i>=0){
                    negative_max[i+1]=negative_max[i];
                    i-=1;
                }
                if(negative_max[i+1]!=v){
                    negative_max[i+1]=v;
                }

                negative_min.emplace_back(v);
                int j=negative_min.size()-2;
                while(v>negative_min[j] and j>=0){
                    negative_min[j+1]=negative_min[j];
                    j-=1;
                }
                if(negative_min[j+1]!=v){
                    negative_min[j+1]=v;
                }

            }
            if(negative_max.size()>k){
                negative_max.pop_back();
            }
            if(negative_min.size()>k){
                negative_min.pop_back();
            }


        }
    }

    int m=0,l=0;
    for (int i=0; i<k;i++) {
        if (positive_max.size() != 0) {
            if (negative_max.size() - m > 1 && i < k - 1 && m < negative_max.size() - 1) {
                if(positive_max.size() - l <= 1){
                    positive_max.emplace_back(1);
                }
                if (negative_max[m] * negative_max[m + 1] > positive_max[l] * positive_max[l + 1]) {
                    result = result * negative_max[m] * negative_max[m + 1];
                    i++;
                    m += 2;
                } else {
                    result *= positive_max[l];
                    l++;
                }

            } else {
                result *= positive_max[l];
                l++;
            }
        }
        else if(k%2!=0){
            result *= negative_min[i];
        }
        else{
            result *= negative_max[i];
        }
    }
    return result;
}
