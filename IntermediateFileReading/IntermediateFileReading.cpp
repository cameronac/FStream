// IntermediateFileReading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

//Global Variables
int spaces = 0;
int punctuation = 0;
int capital_letters = 0;

//Function Headers
void ProcessFile(std::ifstream* file);
void ProcessLine(std::string line);

inline bool CheckForSpace(char ch);
inline bool CheckForPunctuation(char ch);
inline bool CheckForCapitalLetters(char ch);

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

	std::cout << "Spaces: " << spaces << std::endl;
	std::cout << "Punctuation: " << punctuation << std::endl;
	std::cout << "Capital Letters: " << capital_letters << std::endl;
}

//Records Information about the line given
void ProcessLine(std::string line) {

	//Search For Spaces and Punctuation
	for (int i = 0; i < line.length(); i++) {
		
		if (CheckForSpace(line[i])) { continue;  }
		if (CheckForPunctuation(line[i])) { continue;  }
		if (CheckForCapitalLetters(line[i])) { continue; }
	}
}


inline bool CheckForSpace(char ch) {
	
	if (std::isspace(ch)) {
		spaces += 1;
		return true;
	}

	return false;
}

inline bool CheckForPunctuation(char ch) {

	if (std::ispunct(ch)) {
		punctuation += 1;
		return true;
	}

	return false;
}

inline bool CheckForCapitalLetters(char ch) {

	if (std::isupper(ch)) {
	
		capital_letters += 1;
		return true;
	}

	return false;
}