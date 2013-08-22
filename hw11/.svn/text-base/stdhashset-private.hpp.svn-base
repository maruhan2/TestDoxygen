/**
 * \file stdhashset-private.hpp
 * \author Kevin McSwiggen and Mars Park
 * 
 * \brief The private implementation of the  StdHashSet.
 *
 */

#include <cstddef>
#include <unordered_set>
#include <iostream>

template <typename T>
size_t StdHashSet<T>::size() const
{
    return hashSet_.size();
}


template <typename T>
void StdHashSet<T>::insert(const T& x)
{
    hashSet_.insert(x);
}


template <typename T>
bool StdHashSet<T>::exists(const T& x) const
{
    if (hashSet_.find(x) == hashSet_.end())
    {
        return false;
    }
    else
    {
        return true;
    }
}

template <typename T>
void StdHashSet<T>::debug() const
{
    // We cannot access debugging information for STL classes.
    std::cerr << "No statistics available." << std::endl;
}
