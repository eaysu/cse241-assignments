#include <iostream>
#include <vector>
#include <fstream>
#include "SparseVector.h"

using namespace std;

SparseVector::SparseVector()
{
}

SparseVector::SparseVector(string filename)
{
    int index, temp; 
    char ch;
    double data;

    ifstream cinfromfile;

    cinfromfile.open(filename); /* opens file */

    cinfromfile >> index >> ch >> data;

    for(int i = 0;i < index - 1;++i)
    {
        storage_vector.push_back(0.0); /* assign zero to non-index */
    }

    storage_vector.push_back(data); /* store data */

    temp = index;

    while(!cinfromfile.eof())
    {
        cinfromfile >> index >> ch >> data;

        for(int i = 0;i < (index - temp - 1);++i)
        {
            storage_vector.push_back(0.0); /* assign zero to non-index */
        }

        storage_vector.push_back(data); /* store data */

        temp = index;
    }
}

const SparseVector SparseVector::operator+(const SparseVector &sparse_vec) const
{
    SparseVector sum;

    if(storage_vector.size() < sparse_vec.storage_vector.size())
    {
        sum = *this;

        for(int i = 0;i < (sparse_vec.storage_vector.size() - storage_vector.size());++i)
        {
            sum.storage_vector.push_back(0.0); /* assign zero to small vector */
        }

        for(int i = 0;i < sum.storage_vector.size();++i)
        {
            sum.storage_vector.at(i) += sparse_vec.storage_vector.at(i); /* sum operation */
        }
    }

    else if(storage_vector.size() > sparse_vec.storage_vector.size())
    {
        sum = sparse_vec;

        for(int i = 0;i < (storage_vector.size() - sparse_vec.storage_vector.size());++i)
        {
            sum.storage_vector.push_back(0.0); /* assign zero to small vector */
        }

        for(int i = 0;i < sum.storage_vector.size();++i)
        {
            sum.storage_vector.at(i) += storage_vector.at(i); /* sum operation */
        }
    }

    else if(storage_vector.size() == sparse_vec.storage_vector.size())
    {
        sum = sparse_vec;

        for(int i = 0;i < sum.storage_vector.size();++i)
        {
            sum.storage_vector.at(i) += storage_vector.at(i); /* sum operation */
        }
    }

    return sum;
}

const SparseVector SparseVector::operator-(const SparseVector &sparse_vec) const
{
    SparseVector sub;

    if(storage_vector.size() < sparse_vec.storage_vector.size())
    {
        sub = *this;

        for(int i = 0;i < (sparse_vec.storage_vector.size() - storage_vector.size());++i)
        {
            sub.storage_vector.push_back(0.0); /* assign zero to small vector */
        }

        for(int i = 0;i < sub.storage_vector.size();++i)
        {
            sub.storage_vector.at(i) -= sparse_vec.storage_vector.at(i); /* substraction */
        }
    }

    else if(storage_vector.size() > sparse_vec.storage_vector.size())
    {
        sub = sparse_vec;

        for(int i = 0;i < (storage_vector.size() - sparse_vec.storage_vector.size());++i)
        {
            sub.storage_vector.push_back(0.0); /* assign zero to small vector */
        }

        for(int i = 0;i < sub.storage_vector.size();++i)
        {
            sub.storage_vector.at(i) -= storage_vector.at(i); /* substraction */
        }
    }

    else if(storage_vector.size() == sparse_vec.storage_vector.size())
    {
        sub = sparse_vec;

        for(int i = 0;i < sub.storage_vector.size();++i)
        {
            sub.storage_vector.at(i) -= storage_vector.at(i); /* substraction */
        }
    }

    return sub;
}

const SparseVector SparseVector::operator-() const
{
    SparseVector temp = *this;

    for(int i = 0;i < storage_vector.size();++i)
    {
        temp.storage_vector.at(i) *= -1; /* negotiate data */
    }

    return temp;
}

const SparseVector& SparseVector::operator=(const SparseVector &sparse_vec)
{
    storage_vector = sparse_vec.storage_vector; /* assign data */

    return *this;
}

ostream &operator<<(ostream &out, const SparseVector &sparse_vec) /* printing results to output file */
{
    for(int i = 0;i < sparse_vec.storage_vector.size();++i)
    {
        if(sparse_vec.storage_vector.at(i) != 0.0)
        {
            out << i + 1 << ":" << sparse_vec.storage_vector.at(i) << " ";
        }
    }

    return out;
}

double dot(const SparseVector &sparse_vec1, const SparseVector &sparse_vec2) /* dot function */
{
    double result = 0;

    if(sparse_vec1.storage_vector.size() < sparse_vec2.storage_vector.size())
    {
        for(int i = 0;i < sparse_vec1.storage_vector.size();++i) /* multiply data by the size of the smallest vector */
        {
            result += sparse_vec1.storage_vector.at(i) * sparse_vec2.storage_vector.at(i);
        }
    }

    else if(sparse_vec1.storage_vector.size() > sparse_vec2.storage_vector.size())
    {
        for(int i = 0;i < sparse_vec2.storage_vector.size();++i) /* multiply data by the size of the smallest vector */
        {
            result += sparse_vec1.storage_vector.at(i) * sparse_vec2.storage_vector.at(i);
        }
    }

    else if(sparse_vec1.storage_vector.size() == sparse_vec2.storage_vector.size())
    {
        for(int i = 0;i < sparse_vec1.storage_vector.size();++i) /* multiply data */
        {
            result += sparse_vec1.storage_vector.at(i) * sparse_vec2.storage_vector.at(i);
        }
    }

    return result;
}



