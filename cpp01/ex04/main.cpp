#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>

std::string	remplace_occurence(std::string from, std::string delim, std::string into)
{
	std::string	ret;
	size_t		pos;

	pos = 0;
	do 	{
		pos = from.find(delim, pos);
		if (pos == std::string::npos){
			break ;
		}
		from.erase(pos, delim.length());
		from.insert(pos, into);
	} while (pos += into.length());
	ret = from;
	return ret;
}

void	create_file(std::string content, char **av){
	std::string	toFile;
	std::string	nameFile;

	toFile = remplace_occurence(content, std::string(av[2]), std::string(av[3]));
	std::cout << "new file content :" << std::endl << "\t" <<toFile << std::endl;
	nameFile = std::string(av[1]) + ".remplace";
	std::ofstream outfile (nameFile.c_str());
	outfile << toFile;
	outfile.close();
}

int main(int ac, char **av)
{
	std::string	content;

	if (ac != 4){
		std::cerr << "invalid number of arguments" << std::endl;
		return (1);
	} else if (!strlen(av[1]) || !strlen(av[2]) || !strlen(av[3]))
	{
		std::cerr << "empty argument" << std::endl;
		return (1);
	}
	std::ifstream file(av[1]);
	if (file){
		std::ostringstream buf;
		buf << file.rdbuf();
		content = buf.str();
	} else {
		std::cerr << "Open file error" << std::endl;
		return (1);
	}
	std::cout << "Convert " << av[2] << " into " << av[3] << std::endl;
	std::cout << "input content :" << std::endl << "\t" <<content << std::endl;
	create_file(content, av);
}
