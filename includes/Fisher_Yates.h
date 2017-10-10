#pragma once

#include <iostream>
#include <random>
#include <vector>
#include <cstdlib>

class Fisher_Yates
{
private:
    int length;
    std::vector<int> value;
public:
    Fisher_Yates() { this->length = 1; this->value = std::vector<int>(1); }
    Fisher_Yates(int);
    void initialize(int);
    int getLength() { return this->length; }
    void setLength(int len) { this->initialize(len); }
    std::vector<int> getValue() { return this->value; }
    void shuffle(int first_index=-1);
};
