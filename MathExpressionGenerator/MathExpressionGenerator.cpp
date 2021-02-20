// ReadAndWriteMathExpressions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <sstream>


class MathExpressionGenerator {

private:
    int* left_value = nullptr;
    int* right_value = nullptr;
    bool* sign = nullptr;
    

public:
    int number_of_expressions = 0;

    //Constructor
    MathExpressionGenerator(int number_of_expressions) {
        left_value = new int[number_of_expressions];
        right_value = new int[number_of_expressions];
        this->number_of_expressions = number_of_expressions;
        sign = new bool[number_of_expressions];
    }

    //Destructor
    ~MathExpressionGenerator() {
        delete[]left_value;
        delete[]right_value;
        delete[]sign;
    }

    std::string GetExpression(int index) {
         
        if (sign[index]) {
            int result = left_value[index] + right_value[index];
            return std::to_string(left_value[index]) + " " + "+" + " " + std::to_string(right_value[index]) + " = " + std::to_string(result);

        }
        else {
            int result = left_value[index] - right_value[index];
            return std::to_string(left_value[index]) + " " + "-" + " " + std::to_string(right_value[index]) + " = " + std::to_string(result);
        }
    }

    void GenerateExpressions() {
        
        for (int i = 0; i < number_of_expressions; i++) {
            GenerateSign(i);
            GenerateValues(i);
        }
    }

private:
    
    void GenerateSign(int i) {
        sign[i] = rand() % 2;
    }

    void GenerateValues(int i) {

        left_value[i] = rand() % 223;
        right_value[i] = rand() % 223; 
    }
};


int main()
{
    //Initialize Random Seed
    srand(time(NULL));

    //Variables and Objects
    MathExpressionGenerator mathGenerator = MathExpressionGenerator(50);
    std::string directory = "newFile.txt";

    //File Objects
    std::ofstream oFile;

    //Initialization
    mathGenerator.GenerateExpressions();
    oFile.open(directory);


    //Write to File
    if (oFile.is_open()) {

        for (int i = 0; i < mathGenerator.number_of_expressions; i++) {
            
            oFile << mathGenerator.GetExpression(i) << "\n";
        }
    }
    else {
        std::cout << "Couldn't open file!";
    }


    oFile.close();

    return 0;
}



