// Copyright (c) 2022 Yiyun Qin All rights reserved
//
// Created by Yiyun Qin
// Created in May 2022
// This is a math program, calculating the area of the triangle

#include <iostream>
#include <string>
#include <iomanip>
#include <random>


template<int row, int column>
int AverageNumbers(int (&rowList)[row][column]) {
    // This function calculates the area of the triangle

    // process & output
    int total = 0;
    float average;

    for (int rowNumber = 0; rowNumber < row; rowNumber++) {
        for (int columnNumber = 0; columnNumber < column; columnNumber++) {
            total = total + rowList[rowNumber][columnNumber];
        }
    }
    average = total / (row * column);
    return average;
}


int main() {
    // This function does try and catch
    const int rowInteger = 3;
    const int columnInteger = 4;
    int aSingleNumber;
    float average;
    int rowList[rowInteger][columnInteger];

    // process
    std::cout << "" << std::endl;
    try {
        for (int rowNumber = 0; rowNumber < rowInteger; rowNumber++) {
            for (int columnNumber = 0; columnNumber < columnInteger; columnNumber++) {
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
        }
        average = AverageNumbers(rowList);
        std::cout << "\n The average of all the numbers is " << std::fixed
        << std::setprecision(2) << std::setfill('0') << average << "."
        << std::endl;
    } catch (std::invalid_argument) {
        std::cout << "Invalid number!" << std::endl;
        std::cout << "\nDone." << std::endl;
    }
}
