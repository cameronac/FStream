// FStreamExample.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include <string>

/* FStream: 
	-ofstream: write to files
	-ifstream: read from files
	-fstream: read and write from files
*/

int main()
{
	//Variables
	const std::string directory = "example.txt";
	std::string line = "";

	//Create a File and Output to it
	std::ofstream w_file;
	w_file.open(directory);
	w_file << "File Output!\n";
	w_file.close();

	//Read From Created File
	std::ifstream r_file;
	r_file.open(directory);

	if (r_file.is_open()) {
		while (std::getline(r_file, line)) {
			std::cout << line << '\n';
		}

		r_file.close();
	}
	else {
		std::cout << "Unable to open file";
	}

	return 0;
}


