#include <gtest/gtest.h>
#include "ConvertEndian.h"

namespace ConvertEndianNS 
{

class TestConvertEndianFixture : public ::testing::TestWithParam<::std::tuple<uint32_t, uint32_t>>
{
public:
    ConvertEndian convertEndian;
};

TEST_P( TestConvertEndianFixture, test__ConvertEndian )
{
    auto inp = ::std::get<0>( GetParam() );
    auto outp = ::std::get<1>( GetParam() );
    ASSERT_EQ( convertEndian.convert( inp ), outp );
}

INSTANTIATE_TEST_SUITE_P( TestConvertEndian, TestConvertEndianFixture, ::testing::Values( 
    ::std::make_tuple( 0x12345678, 0x78563412 ),
    ::std::make_tuple( 0x01020304, 0x04030201 ) ) );

} // namespace ConvertEndian