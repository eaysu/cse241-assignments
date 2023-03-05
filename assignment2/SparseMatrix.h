#ifndef _SPARSE_MATRIX_H
#define _SPARSE_MATRIX_H

#include <iostream>
#include <vector>

using namespace std;

class SparseMatrix
{
public:
    SparseMatrix();
    SparseMatrix(string filename);
    const SparseMatrix operator+(const SparseMatrix &sparse_matrix) const;
    const SparseMatrix operator-(const SparseMatrix &sparse_matrix) const;
    const SparseMatrix operator-() const;
    const SparseMatrix &operator=(const SparseMatrix &sparse_matrix);
    friend ostream& operator<<(ostream &out, const SparseMatrix &sparse_matrix);
    const SparseMatrix operator*(const SparseMatrix &sparse_matrix) const;
    const SparseMatrix transpose();

private:
    vector<vector<double>> storage_matrix;
};

#endif