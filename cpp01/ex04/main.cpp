/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:43:45 by loruzqui          #+#    #+#             */
/*   Updated: 2025/06/27 09:59:14 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

int	replace(char **argv, std::string str)
{
	std::ofstream	outfile; //std::ofstream -> file to write -> output
	int				pos;

	outfile.open((std::string(argv[1]) + ".replace").c_str()); //file input + .replace
	if (outfile.fail()) //if it fails to open
		return (1);
	for (int i = 0; i < (int)str.size(); i++)
	{
		pos = str.find(argv[2], i); //search word to replace
		if (pos != -1 && pos == i)
		{
			outfile << argv[3];
			i += std::string(argv[2]).size() - 1;
		}
		else
			outfile << str[i];
	}
	outfile.close();
	return (0);
}

int	main(int argc, char **argv)
{
	char			c;
	std::ifstream	infile; //std::ifstream -> file to read -> input
	std::string		str;

	if (argc != 4)
	{
		std::cout << "usage: replace <file> old_word new_word" << std::endl;
		return (1);
	}
	infile.open(argv[1]);
	if (infile.fail()) //if it fails to open
	{
		std::cout << "Error: " << argv[1] << ": no such file or directory" << std::endl;
		return (1);
	}
	/*
	std::noskipws
		- When you read with >> in C++, whitespace is automatically skipped
		- Tells the program NOT to skip spaces
	*/
	while(!infile.eof() && infile >> std::noskipws >> c)
		str += c;
	infile.close();
	return (replace(argv, str));
}
