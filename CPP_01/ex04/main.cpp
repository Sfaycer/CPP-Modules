#include <string>
#include <iostream>
#include <fstream>

std::string change_line(std::string str, std::string s1, std::string s2)
{
	size_t s1_len;
	size_t i;

	s1_len = s1.size();
	i = str.find(s1);
	while (i != std::string::npos)
	{
		str.erase(i, s1_len);
		str.insert(i, s2);
		i = str.find(s1, i + 1);
	}
	return (str);
}

int replace(std::string filename, std::string s1, std::string s2)
{
	std::string str;

	std::ifstream og_file(filename);
	if (!og_file.is_open())
		return (1);

	std::ofstream replace_file(filename + ".replace", std::fstream::trunc);
	if (!replace_file.is_open())
		return (1);
	
	while (std::getline(og_file, str))
		replace_file << change_line(str, s1, s2) << std::endl;
	og_file.close();
	replace_file.close();
	return (0);
}

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::string filename = argv[1];
		std::string s1 = argv[2];
		std::string s2 = argv[3];
		
		if (filename.size() == 0 || s1.size() == 0 || s2.size() == 0)
		{
			std::cout << "Input arguments cannot be empty" << std::endl;
			return (1);
		}
		if (replace(filename, s1, s2))
			std::cout << "Error somewhere with file manipulation" << std::endl;
		else
			std::cout << "Replacement recorded in " << filename << ".replace file" << std::endl;
	}
	else
		std::cout << "Incorrect number of arguments" << std::endl;
	return (0);
}
