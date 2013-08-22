/**
 * \file abstractset.hpp
 * \author Kevin McSwiggen and Mars Park
 * 
 * \brief Abstract template AbstractSet class
 *
 */

#ifndef ABSTRACTSET_HPP_INCLUDED
#define ABSTRACTSET_HPP_INCLUDED 1

#include <ostream>
#include <cstddef>

/**
 * \class AbstractSet
 * \brief AbstractSet to be inherited.
 *
 */
template <typename T>
class AbstractSet
{
public:
    /// Destructor for the set.
    virtual ~AbstractSet() {}
    /// Size of the set.
    virtual size_t size() const = 0;
    /// Inserts an element into the set.
    virtual void insert(const T& x) = 0;
    /// Checks if the element is in the set.
    virtual bool exists(const T& x) const = 0;
    /// Prints debugging information to cerr.
    virtual void debug() const = 0;
};

#endif // ABSTRACTSET_HPP_INCLUDED
