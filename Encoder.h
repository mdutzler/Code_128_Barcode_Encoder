//
// Created by Manuel on 15.11.2026.
//

#ifndef CODE_128_BARCODE_ENCODER_ENCODER_H
#define CODE_128_BARCODE_ENCODER_ENCODER_H
#include <string>
#include <vector>


class Encoder
{
public:
    /// Encodes ASCII text using Code 128 Subset B
    /// @param input ASCII text to encode
    /// @param position Starts at 0. On failure, gives error position.
    /// @param correctValues output vector
    /// @return true if entire input was encoded successful, else false
    static bool TryEncode(const std::string &input, int &position, std::pmr::vector<int> &correctValues);
};


#endif //CODE_128_BARCODE_ENCODER_ENCODER_H
