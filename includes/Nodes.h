#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <limits>

class Node
{
private:
    double X;
    double Y;
public:
    Node() { this->X = 0; this->Y = 0; }
    Node(double a) { this->X = a; this->Y = a; }
    Node(double x, double y) { this->X = x; this->Y = y; }
    double getX() { return this->X; }
    double getY() { return this->Y; }
    void setX(double X) { this->X = X; }
    void setY(double Y) { this->Y = Y; }
    double distance(Node n) { return std::sqrt(std::pow(this->X - n.X, 2) + std::pow(this->Y - n.Y, 2)); }
};

class Nodes
{
private:
    std::vector<Node> nodes;
public:
    Nodes() {}
    Nodes(char*); // get nodes from something file(e.g. *.csv, *.txt)
    int getSize() { return this->nodes.size(); }
    int addNode(Node n, int index=std::numeric_limits<int>::max());
    Node removeNode(int index=std::numeric_limits<int>::max());
    double distance(int, int);
    double getPathLength(std::vector<int>);
};
