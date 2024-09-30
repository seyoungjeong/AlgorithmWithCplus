#include <fstream>
#include <gtest/gtest.h>

#include "FindBitPattern.h"

using namespace std;

// pattern, expected return 
class TestFindBitPatternFixtue 
    : public ::testing::TestWithParam<::std::tuple<
        vector<uint32_t>, 
        bool>>
{
public:
    const string file_name = "bitstream.bin";
};

TEST_P( TestFindBitPatternFixtue, test_FindBitPattern )
{
        ifstream tgt_file( this->file_name, ios::in | ios::binary );
        if ( tgt_file.is_open() )
        {
            tgt_file.read( );
        }

}

INSTANTIATE_TEST_CASE_P( TestFindBitPattern, TestFindBitPatternFixtue, ::testing::Values(
    :make_tuple( vector<uint32_t>{ 12 }, true) ) );
