/**
 * \file stdtreeset-private.hpp
 * \author Kevin McSwiggen and Mars Park
 * 
 * \brief The private implementation of the StdTreeSet template.
 *
 */

#include <cstddef>
#include <set>
#include <iostream>

template <typename T>
size_t StdTreeSet<T>::size() const
{
    return treeSet_.size();
}


template <typename T>
void StdTreeSet<T>::insert(const T& x)
{
    treeSet_.insert(x);
}


template <typename T>
bool StdTreeSet<T>::exists(const T& x) const
{
    if (treeSet_.find(x) == treeSet_.end())
    {
        return false;
    }
    else
    {
        return true;
    }
}

template <typename T>
void StdTreeSet<T>::debug() const
{
    // We cannot access debugging information for STL classes.
    std::cerr << "No statistics available." << std::endl;
}
