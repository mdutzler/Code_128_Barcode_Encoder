#include <iostream>
#include <vector>

#include "Encoder.h"

int main()
{
    while (true)
    {
        // Input
        std::string input;
        std::cout << "Text eingeben (Leeres Enter beendet): ";
        std::getline(std::cin, input);

        if (input.empty())
            break;

        // Encode
        int position = 0;
        std::pmr::vector<int> correctValues;

        if (!Encoder::TryEncode(input, position, correctValues))
        {
            // Error Handling
            std::cout << "Ungueltiges Symbol '" << input.at(position-1) << "' an Stelle " << position << "." << "\n\n";
            continue;
        }

        // Output
        for (const int value: correctValues)
            std::cout << value << " ";

        std::cout << 106 << "\n\n"; // Checksum and Stopcode
    }

    return 0;
}
