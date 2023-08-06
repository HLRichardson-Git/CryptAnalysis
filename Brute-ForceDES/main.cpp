/*
    By: Hunter Richardson
    Date: 8/5/2023

    For the purpose of education
*/

#include <iostream>
#include <cmath>
#include <string>
#include <bits/stdc++.h>

#include <chrono>
#include <thread>

#include "KeySchedule.h"
#include "DES.h"


void printProgressBar(unsigned long long progress, unsigned long long total, int barWidth = 50)
{
    float percentage = static_cast<float>(progress) / total;
    int barProgress = static_cast<int>(percentage * barWidth);

    std::cout << "[";
    for (int i = 0; i < barWidth; ++i) {
        if (i < barProgress) {
            std::cout << "=";
        }
        else {
            std::cout << " ";
        }
    }
    std::cout << "] " << static_cast<int>(percentage * 100.0) << "%\r";
    std::cout.flush();
}

// Need known Plaintext and Ciphertext pair
const std::string Plaintext = "1010101111001101111001101010101111001101000100110010010100110110";
const std::string knownCipherText = "1001011110101011011101010000000011010111110001110011101000111010";

int main()
{

    const unsigned long long totalIterations = static_cast<unsigned long long>(pow(2, 56));
    const unsigned long long updateFrequency = static_cast<unsigned long long>(0.01 * pow(2, 56));

    std::string testKey = "";

    for (unsigned long long i = 0; i < totalIterations; i++)
    {
        // generate key candidate
        testKey = std::bitset<64>(i).to_string();
        
        // generate key schedule for the candidate
        KeySchedule Key(testKey);
        Key.generateKeySchedule();

        // decrypt using key candidate
        std::string canidatePlaintext = DES::algorithm(false, knownCipherText, Key.keyRounds);

        // if found save the candidate, note could be false positive
        if (canidatePlaintext == Plaintext)
        {
            std::string foundKey = testKey;
        }

        // update progress bar on each 1% of work complete
        if (i % updateFrequency == 0 || i == totalIterations) {
            printProgressBar(i, totalIterations);
        }

    }
    std::cout << "Found Key: " << testKey << std::endl;
}

