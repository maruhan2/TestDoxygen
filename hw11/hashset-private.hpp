/**
 * \file hashset-private.hpp
 * \author Kevin McSwiggen and Mars Park
 *
 * \brief The private implementation of the HashSet template.
 *
 */

#include <iostream>
#include <cstddef>
#include <algorithm>

/**
 * We used a simple 50% load factor, which seemed to be sufficient to keep
 * overhead reasonable while not undermining our assumption of constant
 * amortized time.
 */
template <typename T>
const double HashSet<T>::LOAD_FACTOR = 0.5;

template <typename T>
HashSet<T>::HashSet()
    : size_(0), buckets_(2), reallocations_(0), collisions_(0), 
      maximal_(0)
{
    hashTable_ = new Element[buckets_];

    for (size_t i=0; i<buckets_; ++i)
    {
        hashTable_[i].used_ = false;
        hashTable_[i].data_ = NULL;
    }
}

template <typename T>
HashSet<T>::~HashSet()
{
    for (size_t i = 0; i < buckets_; ++i)
    {
        if (hashTable_[i].used_ && hashTable_[i].data_ != NULL)
        {
            delete hashTable_[i].data_;
            hashTable_[i].data_ = NULL;
        }
    }

    delete [] hashTable_;
    
}

template <typename T>
size_t HashSet<T>::size() const
{
    return size_;
}

template <typename T>
void HashSet<T>::insert(const T& x)
{
    size_t key = myhash(x) % buckets_;
    size_t attempts = 0;

    while (hashTable_[key].used_)
    {
        ++key;
        ++attempts;

        if (key == buckets_)
        {
            key = 0;
        }
    }

    if (attempts != 0)
    {
        ++collisions_;
    }
    
    if (attempts > maximal_)
    {
        maximal_ = attempts;
    }

    hashTable_[key].used_ = true;
    hashTable_[key].data_ = new T(x);

    ++size_;

    if (double(size_) / double(buckets_) > LOAD_FACTOR)
    {
        rehash(buckets_ * RESIZE_FACTOR);
    }
}


template <typename T>
bool HashSet<T>::exists(const T& x) const
{
    size_t key = myhash(x) % buckets_;
    size_t attempts = 0;

    while (hashTable_[key].used_ && !(*(hashTable_[key].data_) == x))
    {
        ++key;
        ++attempts;

        if (key == buckets_)
        {
            key = 0;
        }
    }

    if (hashTable_[key].used_ && *(hashTable_[key].data_) == x)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T>
size_t HashSet<T>::buckets() const
{
    return buckets_;
}

template <typename T>
size_t HashSet<T>::reallocations() const
{
    return reallocations_;
}

template <typename T>
size_t HashSet<T>::collisions() const
{
    return collisions_;
}

template <typename T>
size_t HashSet<T>::maximal() const
{
    return maximal_;
}

template <typename T>
void HashSet<T>::debug() const
{
    std::cerr << reallocations() << " expansions, load factor "
         << double(size())/double(buckets()) << ", " << collisions()
         << " collisions, longest run " << maximal() << std::endl;
}

template <typename T>
HashSet<T>::HashSet(size_t capacity)
    : size_(0), buckets_(capacity), reallocations_(0), collisions_(0), 
      maximal_(0)
{
    hashTable_ = new Element[buckets_];

    for (size_t i=0; i<buckets_; ++i)
    {
        hashTable_[i].used_ = false;
        hashTable_[i].data_ = NULL;
    }
}

template <typename T>    
void HashSet<T>::rehash(size_t capacity)
{
    HashSet<T> tempHashSet(capacity);


    for (size_t i = 0; i < buckets_; ++i)
    {
        if (hashTable_[i].used_)
        {
            tempHashSet.insert(*hashTable_[i].data_);
        }
    }

    std::swap(buckets_, tempHashSet.buckets_);
    std::swap(hashTable_, tempHashSet.hashTable_);

    ++reallocations_;
}
