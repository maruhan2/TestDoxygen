/**
 * \file stdtreeset.hpp
 * \author Kevin McSwiggen and Mars Park
 * 
 * \brief The declaration of StdTreeSet.
 *
 */

#ifndef STDTREESET_HPP_INCLUDED
#define STDTREESET_HPP_INCLUDED 1

#include <cstddef>
#include <set>

#include "abstractset.hpp"

 /**
 * \class StdTreeSet
 * \brief Wrapper class for STL set.
 *
 * \details Compiler synthesized constructor and destructor are adequate.
 *
 */
 template <typename T>
 class StdTreeSet : public AbstractSet<T>
 {
 public:
    /// Returns the number of objects stored in the set.
    size_t size() const;

    /// Inserts the element into the set.
    void insert(const T& x);

    /// Determines whether the element is in the set.
    bool exists(const T& x) const;

    /// Prints the debugging information to cerr.
    void debug() const;

private:
    std::set<T> treeSet_;
};

#include "stdtreeset-private.hpp"

#endif // STDTREESET_HPP_INCLUDED
