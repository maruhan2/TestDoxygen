/**
 * \file stdtreeset-tests.hpp
 * \author Kevin McSwiggen and Mars Park
 * 
 */


#include "stdtreeset.hpp"

#define USE_STDTREESET 1
#include "generic-set-tests.cpp"

/// Testing that trees are size 0 when empty and 1 when inserted.
TEST(TreesetOnly, BasicTreeSizeTests)
{
    intset_t nums;
    EXPECT_EQ(0, nums.size());
    nums.insert(5);
    EXPECT_EQ(1, nums.size());
}

/// Testing that the size is updated correctly.
TEST(TreesetOnly, ComplexTreeSizeTests)
{
    intset_t scatteredNums;
    int insertValues[15] = {14,51,78,44,81,46,72,31,59,94,80,66,65,23,49};

    for (size_t i = 0; i < 15; ++i)
    {
        scatteredNums.insert(insertValues[i]);
    }

    EXPECT_EQ(15, scatteredNums.size());
}

/// Testing that the exist function works.
TEST(TreesetOnly, ExistTest)
{
    intset_t scatteredNums;
    int insertValues[15] = {14,51,78,44,81,46,72,31,59,94,80,66,65,23,49};

    for (size_t i = 0; i < 15; ++i)
    {
        scatteredNums.insert(insertValues[i]);
    }

    EXPECT_EQ(true, scatteredNums.exists(78));
    EXPECT_EQ(true, scatteredNums.exists(51));
    EXPECT_EQ(false, scatteredNums.exists(0));
}
