cmake_minimum_required(VERSION 4.4)
project(Code_128_Barcode_Encoder)

set(CMAKE_CXX_STANDARD 26)

add_executable(Code_128_Barcode_Encoder main.cpp
        Encoder.cpp
        Encoder.h
)

# FETCH Catch2 for UNIT Test

Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.8.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)

#
add_executable(EncoderTests Tests/EncoderTests.cpp Encoder.cpp)
target_link_libraries(EncoderTests PRIVATE Catch2::Catch2WithMain)