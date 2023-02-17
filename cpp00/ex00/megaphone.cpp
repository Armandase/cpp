#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc <= 1){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for(size_t i = 1; i < (size_t)argc; i++)
	{
		std::string str = argv[i];
		for (size_t j = 0; j < str.length(); j++)
			std::cout << (char)std::toupper(argv[i][j]);
	}
	std::cout << std::endl;
	return (0);
}
