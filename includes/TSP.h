#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <limits>
#include "Nodes.h"
#include "Fisher_Yates.h"

class TSP
{
private:
    double epsilon;
    double delta;
    double ans_length = std::numeric_limits<double>::max();
    Nodes problem;
    std::vector<int> answer;
    Fisher_Yates fisher_yates;
public:
	TSP() { this->epsilon = 0.01; this->epsilon = 0.01; }
    TSP(double epsilon, double delta) { this->epsilon = epsilon; this->delta = delta; }
    TSP(char* filename); // データセットをファイルから読み込んで問題を設定する場合
    TSP(char* filename, double epsilon, double delta);
    void main(); // 解の導出
    void readFile(char* filename);
    void setEpsilon(double e) { this->epsilon = e; }
    void setDelta(double d) { this->delta = d; }
    void setParameter(double e, double d) { this->setEpsilon(e); this->setDelta(d); }
    void initialize(char* f, double e, double d) { this->readFile(f); this->setParameter(e, d); }
    double getEpsilon() { return this->epsilon; }
    double getDelta() { return this->delta; }
    double getAnsLength() { return this->ans_length; }
};
