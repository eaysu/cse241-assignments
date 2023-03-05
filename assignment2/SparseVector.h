#ifndef _SPARSE_VECTOR_H
#define _SPARSE_VECTOR_H

#include <iostream>
#include <vector>

using namespace std;

class SparseVector
{
public:
    SparseVector();
    SparseVector(string filename); /* gets inputs from files, stores inputs into the vector */
    const SparseVector operator+(const SparseVector &sparse_vec) const; /* adding vectors */
    const SparseVector operator-(const SparseVector &sparse_vec) const; /* substracting vectors */
    const SparseVector operator-() const; /* negotiate vector */
    const SparseVector &operator=(const SparseVector &sparse_vec); /* assign vector */
    friend ostream &operator<<(ostream &out, const SparseVector &sparse_vec); /* writing results to file */
    friend double dot(const SparseVector &sparse_vec1, const SparseVector &sparse_vec2); /* dot function */

private:
    vector<double> storage_vector;
};

#endif