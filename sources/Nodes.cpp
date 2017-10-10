#include "Nodes.h"

Nodes::Nodes(char* filename) {}

int Nodes::addNode(Node n, int index)
{
    if (index == std::numeric_limits<int>::max()) {
        //std::cout << "append node automatically" << std::endl;
        this->nodes.push_back(n);
        return 1;
    }
    else if (index == this->nodes.size()) {
        this->nodes.push_back(n);
        return 1;
    }
    else if (index >= 0 && index < this->nodes.size()) {
        this->nodes.insert(this->nodes.begin() + index, n);
        return 1;
    }
    else {
        std::cout << "addNode index error : index out of range" << std::endl;
        std::exit(0);
    }
}

Node Nodes::removeNode(int index)
{
    if (index == std::numeric_limits<int>::max()) {
        std::cout << "saigo delete" << std::endl;
        index = this->nodes.size() - 1;
    }

    if (index >= 0 and index < nodes.size()) {
        Node n = this->nodes[index];
        this->nodes.erase(this->nodes.begin() + index);
        return n;
    }
    else {
        std::cout << "removeNode index error : index out of range" << std::endl;
        std::exit(0);
    }
}

double Nodes::distance(int index1, int index2)
{
    if (index1 < 0 || index1 >= this->nodes.size() || index2 < 0 || index2 >= this->nodes.size()) {
        std::cout << "Nodes::distance error : index out of range" << std::endl;
        std::exit(0);
    }
    return this->nodes[index1].distance(this->nodes[index2]);
}

double Nodes::getPathLength(std::vector<int> seq)
{
    double ans = this->distance(seq[0], seq[this->nodes.size()-1]);
    for (int i=0; i<this->nodes.size()-1; i++) {
        ans += this->distance(seq[i], seq[i+1]);
    }
    return ans;
}
