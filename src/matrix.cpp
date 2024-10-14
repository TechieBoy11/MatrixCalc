#include "matrix.h"
#include <stdexcept> // For std::invalid_argument

Matrix createMatrix(int rows, int cols) {
    Matrix newMatrix(rows, std::vector<double>(cols, 0.0));
    return newMatrix;
}

Matrix addMatrices(const Matrix& m1, const Matrix& m2) {
    if ( (m1.size() != m2.size()) || (m1[0].size() != m2[0].size()))
        throw std::invalid_argument("Matrices dimensions do not match");

    int row = static_cast<int>(m1.size());
    int colm = static_cast<int>(m1[0].size());
    Matrix result = createMatrix(row, colm);

    for (int i{0}; i<row; i++) {
        for (int j{0}; j<colm; j++)
            result[i][j] = m1[i][j] + m2[i][j];
    }

    return result;
}

Matrix subtractMatrices(const Matrix& m1, const Matrix& m2) {
if ( (m1.size() != m2.size()) || (m1[0].size() != m2[0].size()))
        throw std::invalid_argument("Matrices dimensions do not match");

    int row = static_cast<int>(m1.size());
    int colm = static_cast<int>(m1[0].size());
    Matrix result = createMatrix(row, colm);

    for (int i{0}; i<row; i++) {
        for (int j{0}; j<colm; j++)
            result[i][j] = m1[i][j] - m2[i][j];
    }

    return result;
}

Matrix multiplyMatrices(const Matrix& m1, const Matrix& m2){
    // Check if matrices can be multiplied
    if (m1[0].size() != m2.size()) 
        throw std::invalid_argument("Matrices dimensions do not match");

    int m = static_cast<int>(m1.size());         
    int n = static_cast<int>(m2.size());        
    int p = static_cast<int>(m2[0].size());        
    Matrix result = createMatrix(m, p);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            for (int k = 0; k < n; ++k) 
                result[i][j] += m1[i][k] * m2[k][j];
        }
    }
    
    return result;
}




