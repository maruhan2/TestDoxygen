/**
 * \file set-tests.cpp
 * \author CS 70
 * \brief
 *   You can use this file to test that your set template is properly
 *   generic and doesn't contain any hidden dependencies on being a
 *   hashtable of strings.
 *
 * \details
 *   This code doesn't test the code in any significant way (although
 *   you can use it as a starting point for code that does), it merely
 *   makes sure everything compiles properly.
 */

/******************************************************
 * Compatability Tests
 *
 *     Test for any hidden dependencies of each set on
 *     functions of the template type or included
 *     files.
 * ****************************************************/

// Don't put any #includes before the set inclusion! Otherwise it
// won't be as good a test of whether the header is self-sufficient.
#if !(USE_TREESET || USE_HASHSET || USE_STDTREESET || USE_STDHASHSET)
    #warning No kind of set specified, using TreeSet
    #define USE_TREESET 1
#endif

#if (USE_TREESET + USE_HASHSET + USE_STDTREESET + USE_STDHASHSET) > 1
    #error Only one kind of set should be specified
#endif


#include <ostream> // For std::ostream
#include <cstddef> // For size_t
#include <cassert>

/**
 * \class Cow
 * \brief
 *   Test class which implements the bare minimum to be usable with the sets.
 * \remarks
 *   As this class is very brief and intended purely for testing
 *   purposes, we keep it completely contained within this file. Doing
 *   so on production level code is problematic.
 */
class Cow {
public:
    /// Non-default constructor.
    // (Classes used with our set templates aren't required to have a
    // default constructor.)
    explicit Cow(size_t numHats);

private:
    size_t numHats_;    ///< How many hats does our Cow have?

    // Give external functions friend access
    friend std::ostream& operator<<(std::ostream& out, const Cow& printMe);
#if USE_HASHSET || USE_STDHASHSET
    friend bool operator==(const Cow& lhs, const Cow& rhs);
    friend size_t myhash(const Cow& c);
#endif
#if USE_TREESET || USE_STDTREESET
    friend bool operator<(const Cow& lhs, const Cow& rhs);
#endif
};

Cow::Cow(size_t numHats)
    : numHats_(numHats)
{
    // Nothing (else) to do.
}

// We define an output operator for the Cow type.  (TreeSet *requires* an
// output operator.)

/// Output a Cow in visual form
std::ostream& operator<<(std::ostream& out, const Cow& printMe)
{
    out << std::endl;           // Begin with a blank line

    for (size_t i = 0; i < printMe.numHats_; ++i)
        out << "        _====_\n";

    out << "         (__)\n"    // Shamelessly taken from Debian's (& Ubuntu's)
        << "         (oo)\n"    //    apt-get moo
        << "   /------\\/ \n"   // (apt has "super cow" powers)
        << "  / |    ||  \n"
        << " *  /\\---/\\  \n"
        << "    ~~   ~~  \n";
    return out;
}



#if USE_HASHSET || USE_STDHASHSET

// Classes used with hash tables must also have an equality operator.
// Here, I've defined it as a non-member function.

/// Equality for Cows
bool operator==(const Cow& lhs, const Cow& rhs)
{
    return lhs.numHats_ == rhs.numHats_;
}

/// And we also are expected to provide a hash function.

size_t myhash(const Cow& c)
{
    // Really bad hash function. ;-)
    return c.numHats_ % 2 == 0 ? 42 : c.numHats_;
}

unsigned long myhash(int x)
{
    return x*131;  // Questionable hash function. ;-)
}

#endif

#if USE_TREESET || USE_STDTREESET

// Classes used with trees must also have a less-than operator.  Here, I've
// defined it as a non-member function.

/// Inequality for Cows
bool operator<(const Cow& lhs, const Cow& rhs)
{
    return lhs.numHats_ < rhs.numHats_;
}

#endif



// Explicitly instantiate all our templated classes (normally C++ is lazy
// and only instantiates the things it needs as it needs them, here we make
// it do everything.)
//
// For our testing, we'll test with Cows and ints

#if USE_TREESET
    template class TreeSet<Cow>;
    typedef TreeSet<Cow> cowset_t;
    
    template class TreeSet<int>;
    typedef TreeSet<int> intset_t;
#elif USE_HASHSET
    template class HashSet<Cow>;
    typedef HashSet<Cow> cowset_t;
    
    template class HashSet<int>;
    typedef HashSet<int> intset_t;
#elif USE_STDTREESET
    template class StdTreeSet<Cow>;
    typedef StdTreeSet<Cow> cowset_t;
    
    template class StdTreeSet<int>;
    typedef StdTreeSet<int> intset_t;
#elif USE_STDHASHSET
    template class StdHashSet<Cow>;
    typedef StdHashSet<Cow> cowset_t;
    
    template class StdHashSet<int>;
    typedef StdHashSet<int> intset_t;
#endif


/*****************************************************
 * Functionality Tests
 *
 *      Functionality tests for various Set classes
 * ***************************************************/

#include <gtest/gtest.h>
#include "abstractset.hpp"

// Very minimal testing.

/**
 * \brief Tests whether we can even use the chosen set.
 *
 * \details
 *   Tests:
 *     - Construction of a intset_t
 *     - Creating as an AbstractSet Reference to that set
 *     - Inserting an int
 *     - Checking that there is an int in the set.
 *     - Checking that there isn't an int in the set.
 *
 * \remarks
 *   This code is vastly insufficient for final testing, and intended
 *   as a starting point.
 */
TEST(GeneralTestSuite, basicTests)
{
    // Very minimal testing.
    intset_t nums;
    AbstractSet<int>& numsRef = nums;
    numsRef.insert(4);
    
    // These tests insist that the set is treated as const
    const AbstractSet<int>& constNumsRef = nums;
    EXPECT_TRUE(constNumsRef.exists(4))  << "ERROR 23: Expected a cow";
    EXPECT_FALSE(constNumsRef.exists(1)) << "ERROR 17: Unexpected cow";
}

TEST(GeneralTestSuite, sizeTests)
{
    intset_t nums;
    // A default constructed set has a size of 0.
    EXPECT_EQ(0, nums.size());

    for (int i = 1; i < 10; ++i)
    {
        nums.insert(i);
        EXPECT_EQ(i, nums.size());
    }
}

TEST(GeneralTestSuite, existsTests)
{
    intset_t nums;
    // A default constructed set has no elements.
    EXPECT_FALSE(nums.exists(1));

    for (int i = 1; i < 10; ++i)
    {
        nums.insert(i);
        EXPECT_TRUE(nums.exists(i));
    }
}
