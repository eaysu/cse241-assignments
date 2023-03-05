#include <iostream>
#include <vector>
#include <fstream>
#include "SparseMatrix.h"

using namespace std;

SparseMatrix::SparseMatrix()
{
}

SparseMatrix::SparseMatrix(string filename)
{
}

const SparseMatrix SparseMatrix::operator+(const SparseMatrix &sparse_matrix) const
{
    return *this;
}

const SparseMatrix SparseMatrix::operator-(const SparseMatrix &sparse_matrix) const
{
    return *this;
}

const SparseMatrix SparseMatrix::operator-() const
{
    return *this;
}

const SparseMatrix& SparseMatrix::operator=(const SparseMatrix &sparse_matrix)
{
    return *this;
}

ostream &operator<<(ostream &out, const SparseMatrix &sparse_matrix)
{
    out << "NO TIME LEFT";
    return out;
}

const SparseMatrix& SparseMatrix::operator*(const SparseMatrix &sparse_matrix)
{
    return *this;
}

const SparseMatrix SparseMatrix::transpose()
{
    return *this;
}