//
// Created by Manuel on 15.11.2026.
//

#include <iostream>
#include <string>
#include <vector>

#include "Encoder.h"

bool Encoder::TryEncode(const std::string &input, int &position, std::pmr::vector<int> &correctValues)
{
    constexpr int startcode = 104;
    correctValues.push_back(startcode); // Subset B Value
    int checksum = startcode;

    for (const unsigned char symbol: input)
    {
        int value = symbol; // char --> ASCI wert
        value = value - 32;

        position++;
        if (value < 0 || value > 95)
            return false;

        correctValues.push_back(value);
        checksum += value * position;
    }

    checksum = checksum % 103;

    correctValues.push_back(checksum);

    return true;
}
