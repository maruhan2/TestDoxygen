/**
 * \file stdhashset.hpp
 * \author Kevin McSwiggen and Mars Park
 * 
 * \brief The declaration of StdHashSet.
 *
 */

#ifndef STDHASHSET_HPP_INCLUDED
#define STDHASHSET_HPP_INCLUDED 1

#include <cstddef>
#include <unordered_set>

#include "abstractset.hpp"
 /**
 * \class StdHashSet
 * \brief Wrapper class for STL unordered_set.
 *
 * \details Compiler synthesized constructor and destructor are adequate.
 *
 */
 template <typename T>
 class StdHashSet : public AbstractSet<T>
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
    class MyHash 
    { 
    public:
        // Function application operator. 
        // Lets MyHash objects be called like functions.
        size_t operator()(const T& value) const
        {
            return myhash(value); 
        }
    };
    
    std::unordered_set<T, MyHash> hashSet_;
};

#include "stdhashset-private.hpp"

#endif // STDHASHSET_HPP_INCLUDED
