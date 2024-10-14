#define CATCH_CONFIG_MAIN  // This line tells Catch to provide a main() function

#include <cassert>    
#include <cstdlib>
#include "catch.hpp"
#include "matrix.h"

TEST_CASE("Test1: creat") {
    Matrix matrix = createMatrix(4, 5);
    
    REQUIRE(matrix.size() == 4);
    REQUIRE(matrix[0].size() == 5);
}

TEST_CASE("Test2: Add compatible") {
	Matrix m1 = {{1, 2, 3}, {4, 5, 6}};
    Matrix m2 = {{7, 8, 9}, {10, 11, 12}};
    
    Matrix result = addMatrices(m1, m2);
    Matrix expected = {{8, 10, 12}, {14, 16, 18}};
    
    REQUIRE(result == expected);
}

TEST_CASE("Test3: Add incompatible") {
	Matrix m1 = {{1, 2}, {3, 4}};
    Matrix m2 = {{5, 6, 7}, {8, 9, 10}};
    
    REQUIRE_THROWS_AS(addMatrices(m1, m2), std::invalid_argument);
}

TEST_CASE("Test4: Subtract compatible") {
	Matrix m1 = {{7, 8, 9}, {10, 11, 12}};
    Matrix m2 = {{1, 2, 3}, {4, 5, 6}};
    
    Matrix result = subtractMatrices(m1, m2);
    Matrix expected = {{6, 6, 6}, {6, 6, 6}};
    
    REQUIRE(result == expected);
}

TEST_CASE("Test5: Subtract incompatible") {
	Matrix m1 = {{1, 2}, {3, 4}};
    Matrix m2 = {{5, 6, 7}, {8, 9, 10}};
    
    REQUIRE_THROWS_AS(subtractMatrices(m1, m2), std::invalid_argument);
}

TEST_CASE("Test6: multiply compatible") {
	Matrix m1 = {{1, 2}, {3, 4}};
    Matrix m2 = {{5, 6}, {7, 8}};
    
    Matrix result = multiplyMatrices(m1, m2);
    Matrix expected = {{19, 22}, {43, 50}};
    
    REQUIRE(result == expected);
}

TEST_CASE("Test7: multiply incompatible") {
	Matrix m1 = {{1, 2}};
    Matrix m2 = {{3, 4}, {5, 6}, {7, 8}};

    REQUIRE_THROWS_AS(multiplyMatrices(m1, m2), std::invalid_argument);
}