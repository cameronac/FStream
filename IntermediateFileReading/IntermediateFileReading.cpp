// IntermediateFileReading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

int main()
{
	//Variables
	std::string directory = "100west.txt";
	std::string line = "";

	//Input File
	std::ifstream myFile;
	myFile.open(directory);

	//Getting File Text
	if (myFile.is_open()) {

		//File Loop
		while (std::getline(myFile, line)) {

			//Process Line
			
		}
	}
	else {
		std::cout << "Unable to open file!" << std::endl;
	}

	myFile.close();
}
