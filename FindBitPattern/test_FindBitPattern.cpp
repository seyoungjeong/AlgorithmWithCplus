#include <gtest/gtest.h>

#include "FindBitPattern.h"

const ::std::byte[] src_1 = 
class TestFindBitPatternFixtue 
    : public ::testing::TestWithParam<::std::tuple<
        ::std::array<::std::byte, size_t>,
        ::std::array<::std::byte, size_t>, 
        bool>>
{
};

TEST_P( TestFindBitPatternFixtue, test_FindBitPatternFixtue )
{

}

INSTANTIATE_TEST_SUITE_P( TestFindBitPattern, TestFindBitPatternFixtue, ::testing::Values(
    ::std::make_tuple
 ))
