/**
 * \file hashset.hpp
 * \author Kevin McSwiggen and Mars Park
 *
 * \brief Declares the HashSet class
 *
 */

#ifndef HASHSET_HPP_INCLUDED
#define HASHSET_HPP_INCLUDED 1

#include <ostream>
#include <cstddef>

#include "abstractset.hpp"

/**
 * \class HashSet
 * \brief Hashset for an arbitrary class T.
 *
 * \details This class includes a class Element that has data members that
 *          holds a pointer to a T type object called data_ and a boolean
 *          called used_ that shows if the Element has been inserted into
 *          the hash.
 *
 * \remarks Deletion is not supported.
 *
 */
template <typename T>
class HashSet : public AbstractSet<T>
{
public:
    /**
     * \brief Default constructor for HashSet
     *
     * \details 
     *   Initializes buckets_ as 2 and the remaining data members as 0.
     *   All Elements are initialized as false for used_.
     *
     */
    HashSet();

    ///< Destructor. Deletes the pointers.
    ~HashSet();

    ///< Returns the number of objects stored in the hash.
    size_t size() const;

    /**
     * \brief Inserts the object of type T into the hash.
     * \details
     *   Insert will cause the hash to resize itself when size_/buckets_ is
     *   greater than the load factor.
     *
     * \param x     A reference to a constant T.
     */
    void insert(const T& x);

    /**
     * \brief Checks if the object of type T is in the hash.
     *
     * \param x     A reference to a constant T.
     */
    bool exists(const T& x) const;

    /// Returns the number of buckets.
    size_t buckets() const;

    /// Returns the number of times the hash table has resized itself.
    size_t reallocations() const;

    /// Returns that number of times an insert into the current hash table 
    /// representation has found a non-empty bucket.
    size_t collisions() const;

    /// Returns the length of the longest chain (in the case of separate 
    /// chaining) or cluster (in the case of open addressing) discovered 
    /// so far in the current hash table representation.
    size_t maximal() const;

    /// Prints debugging information for the HashSet to cerr.
    void debug() const;

private:
    static const double LOAD_FACTOR;
    static const size_t RESIZE_FACTOR = 2;

   /**
    * \class Element
    * \brief Stores a constant pointer of type T, and a boolean that checks if
    *        the element has been included in the hash.
    *
    * \details This class uses a pointer to type T since we do not want to
    *          change it.
    *
    */
    class Element
    {
    public:
        const T* data_;
        bool used_;
    };

    ///< Array of Elements.
    Element* hashTable_;

    size_t size_; ///< The number of objects in the hash.
    size_t buckets_; ///< The number of buckets.
    size_t reallocations_; ///< The number of reallocations.
    size_t collisions_; ///< The number of collisions.
    size_t maximal_; ///< The length of the longest chain.


    HashSet(size_t capacity); ///< A constructor with a specific bucket size.

    /**
     * \brief Makes a new hash size a given capacity.
     *
     * \param capacity     The number of buckets that the new hash will have.
     */
    void rehash(size_t capacity);
};

#include "hashset-private.hpp"

#endif // HASHSET_HPP_INCLUDED
