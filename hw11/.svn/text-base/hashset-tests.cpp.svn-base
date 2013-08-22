/**
 * \file hashset-tests.hpp
 * \author Kevin McSwiggen and Mars Park
 * 
 */

unsigned long myhash(int x);                  // Predeclare before any includes
#include "stringhash.hpp"
#include "hashset.hpp"

#define USE_HASHSET 1
#include "generic-set-tests.cpp"

/// Test insert and exists for strings
TEST(stringTestSuite, basicStringTests)
{
    std::string testString = "a";
    HashSet<std::string> stringSet;
    EXPECT_FALSE(stringSet.exists(testString));
    stringSet.insert(testString);
    EXPECT_TRUE(stringSet.exists(testString));
}

/// Test the size() function for strings
TEST(stringTestSuite, sizeTests)
{
    HashSet<std::string> stringSet;
    EXPECT_EQ(stringSet.size(), 0);

    std::string mystring = "";

    for (int i = 1; i < 20; ++i)
    {
        mystring.push_back('a');
        stringSet.insert(mystring);
        EXPECT_EQ(i, stringSet.size());
    }
}
