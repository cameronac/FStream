// IntermediateFileReading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

//Function Headers
void ProcessFile(std::ifstream* file);
void ProcessLine(std::string line);


int main()
{
	//Variables
	std::string directory = "100west.txt";

	//Input File
	std::ifstream myFile;
	myFile.open(directory);

	ProcessFile(&myFile);

	myFile.close();
}

//Looks Through File Line by Line
void ProcessFile(std::ifstream* file) {

	std::string line = "";

	//Getting File Text
	if (file->is_open()) {

		//File Loop
		while (std::getline(*file, line)) {

			//Process Line
			ProcessLine(line);
		}
	}
	else {
		std::cout << "Unable to open file!" << std::endl;
	}
}

//Records Information about the line given
void ProcessLine(std::string line) {

}
