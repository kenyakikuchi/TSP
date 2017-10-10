#include "resources.h"

int main(int argc, char* argv[])
{
	TSP tsp;

	if (argc == 2)
		tsp.readFile(argv[1]);
	else if (argc == 4)
		tsp.initialize(argv[1], std::stof(argv[2]), std::stof(argv[3]));
	else {
		std::cout << "command line argument error" << std::endl;
		return 0;
	}

	tsp.main();

	return 0;
}
