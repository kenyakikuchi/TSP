#include "Fisher_Yates.h"

Fisher_Yates::Fisher_Yates(int n)
{
    this->length = n;
    this->value = std::vector<int>(n);
    for (int i=0; i<this->length; i++) {
        this->value[i] = i;
    }
}

void Fisher_Yates::initialize(int n)
{
    this->length = n;
    this->value = std::vector<int>(n);
    for (int i=0; i<this->length; i++) {
        this->value[i] = i;
    }
}

void Fisher_Yates::shuffle(int first_index)
{
    std::random_device seed_gen;
    std::default_random_engine engine(seed_gen());

    std::vector<int> dummy = this->value;

	int max_index;
	int start_index;
    if (first_index < 0 && first_index >= this->length) {
    	max_index = this->length;
    	start_index = 0;
    }
    else {
    	max_index = this->length - 1;
    	start_index = 1;
    	this->value[0] = dummy[first_index];
    	dummy.erase(dummy.begin() + first_index);
    }

    int num = 0;
    for (int i=0; i<max_index; i++) {
        std::uniform_int_distribution<int> dist(0, max_index - i - 1);
        num = dist(engine);
        this->value[start_index + i] = dummy[num];
        dummy.erase(dummy.begin() + num);
    }
}
