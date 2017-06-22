//
// Created by Krzysiek on 15.03.2017.
//

#ifndef JIMP_EXERCISES_XORCYPHERBREAKER_H
#define JIMP_EXERCISES_XORCYPHERBREAKER_H
#include <iostream>
#include <vector>
using namespace std;
std::string XorCypherBreaker(const std::vector<char> &cryptogram,
                             int key_length,
                             const std::vector<std::string> &dictionary);

bool Guess(const std::vector<char> &cryptogram,
           int key_length,
           const std::vector<std::string> &dictionary,std::string key);


#endif //JIMP_EXERCISES_XORCYPHERBREAKER_H
