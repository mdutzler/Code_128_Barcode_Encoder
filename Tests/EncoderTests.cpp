//
// Created by dutzi on 15.11.2026.
//

#include <catch2/catch_test_macros.hpp>
#include "../Encoder.h"

TEST_CASE("Encode_Hello123_ReturnsExpectedSymbolValuesPositionAndChecksum")
{
    std::string testInput = "HELLO123";

    int position = 0;
    std::pmr::vector<int> correctValues;

    REQUIRE(Encoder::TryEncode(testInput,position, correctValues));

    REQUIRE(position == 8);
    REQUIRE(correctValues.at(0) == 104); // Subset B
    REQUIRE(correctValues.at(1) == 40); // H
    REQUIRE(correctValues.at(2) == 37); // E
    REQUIRE(correctValues.at(3) == 44); // L
    REQUIRE(correctValues.at(4) == 44); // L
    REQUIRE(correctValues.at(5) == 47); // O
    REQUIRE(correctValues.at(6) == 17); // 1
    REQUIRE(correctValues.at(7) == 18); // 2
    REQUIRE(correctValues.at(8) == 19); // 3
    REQUIRE(correctValues.at(9) == 8);  // CHECKSUM
}


TEST_CASE("Encode_TEST§TEST_ReturnsErrorAtCorrectPosition")
{
    std::string testInput = "TEST§TEST";

    int position = 0;
    std::pmr::vector<int> correctValues;

    REQUIRE_FALSE(Encoder::TryEncode(testInput,position, correctValues));

    REQUIRE(position == 5);
}

TEST_CASE("Encode_DEL_EdgeCaseReturnsExpectedSymbolValuesPositionAndChecksum")
{
    std::string testInput = "\x7F"; // = 127 das it DEL in ASCII

    int position = 0;
    std::pmr::vector<int> correctValues;

    REQUIRE(Encoder::TryEncode(testInput,position, correctValues));

    REQUIRE(position == 1);
    REQUIRE(correctValues.at(0) == 104);
    REQUIRE(correctValues.at(1) == 95);
    REQUIRE(correctValues.at(2) == 96); // CHECKSUM 104 + 95 * 1 % 103 = 96
}