#ifndef MATRIX_H
#define MATRIX_H
 #include <vector>

 using Matrix = std::vector<std::vector<double>>;
 
 Matrix createMatrix(int rows, int cols);
 Matrix addMatrices(const Matrix& m1, const Matrix& m2);
 Matrix subtractMatrices(const Matrix& m1, const Matrix& m2);
 Matrix multiplyMatrices(const Matrix& m1, const Matrix& m2);

 #endif