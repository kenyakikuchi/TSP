#include "TSP.h"

std::vector<std::string> split(const std::string& input, char delimiter)
{
    std::istringstream stream(input);

    std::string field;
    std::vector<std::string> result;
    while (std::getline(stream, field, delimiter)) {
        result.push_back(field);
    }
    return result;
}

TSP::TSP(char* filename)
{
	this->readFile(filename);
}

TSP::TSP(char* filename, double epsilon, double delta)
{
	this->epsilon = epsilon;
	this->delta = delta;

	this->readFile(filename);
}

void TSP::main()
{
    int sample_number = std::ceil(log(1/this->delta)/this->epsilon);
    std::cout << "sample number is " << sample_number << std::endl;
    for (int i=0; i<sample_number; i++) {
        this->fisher_yates.shuffle(0);
        double current_length = this->problem.getPathLength(this->fisher_yates.getValue());

        std::cout << current_length << std::endl;
        //std::cout << current_length << ",";
        //for (auto ddd : this->fisher_yates.getValue())
        //	std::cout << ddd << ",";
        //std::cout << std::endl;

        if (this->ans_length > current_length) {
            this->ans_length = current_length;
            this->answer = fisher_yates.getValue();
        }
    }
    std::cout << "answer of " << sample_number << " samples is " << this->ans_length << std::endl;
    //std::cout << "answer of " << sample_number << " samples," << this->ans_length << std::endl;
    //std::cout << "route,";
    //for (auto ddd : this->answer)
    //	std::cout << ddd << ",";
    //std::cout << std::endl;
}

void TSP::readFile(char* filename)
{
    std::ifstream ifs(filename);
    std::string str;

    if (ifs.fail()) {
        std::cout << "file cannot open" << std::endl;
        std::exit(0);
    }

    while (getline(ifs, str)) {
    	std::vector<std::string> s = split(str, ' ');
    	if (s.size() == 3) {
    		this->problem.addNode(Node(std::stod(s[1]), std::stod(s[2])));
    	}
    }

    this->fisher_yates.initialize(this->problem.getSize());
}
