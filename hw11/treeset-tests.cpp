/**
 * \file treeset-tests.hpp
 * \author Kevin McSwiggen and Mars Park
 * 
 */


#include "treeset.hpp"

// This next file defines a number of tests that can be applied to any kind
// of set.  It's a bit odd to #include a cpp file, but it doesn't seem right
// to call it a header since it contains actual function declarations.

#define USE_TREESET 1
#include "generic-set-tests.cpp"

/// Basic tests that check if inserting two elements create an appropriate tree.
TEST(TreesetOnly, basicTreesetTests)
{
    intset_t nums;
    nums.insert(42);
    nums.insert(54);

    // These tests insist that the set is treated as const
    const intset_t& constNums = nums;
    constNums.print(std::cout) << std::endl;
    EXPECT_EQ(constNums.height(), 1);
}

/// Testing that the height of nonexistant nodes is -1 and height with
/// no children is 0.
TEST(TreesetOnly, BasicAVLTreeHeightTests)
{
    intset_t nums;
    const intset_t& constNums = nums;
    EXPECT_EQ(constNums.height(), -1);

    nums.insert(5);
    EXPECT_EQ(nums.height(), 0);        
}

/// Testing the balancing of a scattered AVL Tree.
TEST(TreesetOnly, AVLScatterBalanceTest)
{
    intset_t scatteredNums;
    int insertValues[15] = {14,51,78,44,81,46,72,31,59,94,80,66,65,23,49};

    for (size_t i = 0; i < 15; ++i)
    {
        scatteredNums.insert(insertValues[i]);
    }

    scatteredNums.print(std::cout) << std::endl;

    EXPECT_EQ(4, scatteredNums.height());
}

/// Testing the balancing of a sequential AVL Tree.
TEST(TreesetOnly, AVLSequentialBalanceTests)
{
    intset_t forwardSequentialNums;
    intset_t reverseSequentialNums;

    for (size_t i = 0; i < 31; ++i)
    {
        forwardSequentialNums.insert(i);
        reverseSequentialNums.insert(30-i);
    }

    forwardSequentialNums.print(std::cout) << std::endl;
    reverseSequentialNums.print(std::cout) << std::endl;

    EXPECT_EQ(4, forwardSequentialNums.height());
    EXPECT_EQ(4, reverseSequentialNums.height());
}

/// Testing that trees are size 0 when empty and 1 when inserted.
TEST(TreesetOnly, BasicAVLTreeSizeTests)
{
    intset_t nums;
    EXPECT_EQ(0, nums.size());
    nums.insert(5);
    EXPECT_EQ(1, nums.size());
}

/// Testing that the size is updated correctly.
TEST(TreesetOnly, ComplexAVLTreeSizeTests)
{
    intset_t scatteredNums;
    int insertValues[15] = {14,51,78,44,81,46,72,31,59,94,80,66,65,23,49};

    for (size_t i = 0; i < 15; ++i)
    {
        scatteredNums.insert(insertValues[i]);
    }

    scatteredNums.print(std::cout) << std::endl;

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
