// Copyright (c) 2022 Yiyun Qin All rights reserved
//
// Created by Yiyun Qin
// Created in May 2022
// This is a math program, listing numbers in a table and calculating average

#include <iostream>
#include <iomanip>
#include <random>


template<int row, int column>
float AverageNumbers(int (&rowList)[row][column]) {
    // This function calculates the average of the numbers

    // process & output
    int total = 0;
    float average;

    for (int rowNumber = 0; rowNumber < row; rowNumber++) {
        for (int columnNumber = 0; columnNumber < column; columnNumber++) {
            total = total + rowList[rowNumber][columnNumber];
        }
    }
    average = total / (row * column * 1.00);
    return average;
}


int main() {
    // This function does try and catch
    const int rowInteger = 3;
    const int columnInteger = 2;
    int aSingleNumber;
    float average;
    int rowList[rowInteger][columnInteger];

    // process
    std::cout << "Rows: " << rowInteger << std::endl;
    std::cout << "Columns: " << columnInteger << std::endl;
    std::cout << "" << std::endl;
    try {
        for (int rowNumber = 0; rowNumber < rowInteger; rowNumber++) {
            for (int columnNumber = 0; columnNumber < columnInteger;
            columnNumber++) {
                std::random_device rseed;
                std::mt19937 rgen(rseed());
                std::uniform_int_distribution<int> idist(1, 100);
                aSingleNumber = idist(rgen);
                rowList[rowNumber][columnNumber] = aSingleNumber;
                if (aSingleNumber >= 10) {
                    std::cout << aSingleNumber << " ";
                } else {
                    std::cout << aSingleNumber << "  ";
                }
            }
            std::cout << "" << std::endl;
        }
        average = AverageNumbers(rowList);
        std::cout << "\nThe average of all the numbers is " << std::fixed
        << std::setprecision(2) << std::setfill('0') << average << "."
        << std::endl;
    } catch (std::invalid_argument) {
        std::cout << "Invalid number!" << std::endl;
    }
    std::cout << "\nDone." << std::endl;
}
