//
// Created by mwypych on 01.06.17.
//

#include <gtest/gtest.h>
#include <ArabicRoman.h>

class RomanToArabicConvertionTest: public ::testing::Test{
public:
};

TEST_F(RomanToArabicConvertionTest, CorrectConversionFromRomanToArabicForNumbersLessThan10){
    EXPECT_EQ(2,RomanToArabic("II"));
    EXPECT_EQ(4,RomanToArabic("IV"));
    EXPECT_EQ(5,RomanToArabic("V"));
    EXPECT_EQ(8,RomanToArabic("VIII"));
    EXPECT_EQ(9,RomanToArabic("IX"));
}


TEST_F(RomanToArabicConvertionTest, CorrectConversionFromRomanToArabicForNumbersLessThan100){
    EXPECT_EQ(50,RomanToArabic("L"));
    EXPECT_EQ(40,RomanToArabic("XL"));
    EXPECT_EQ(5,RomanToArabic("V"));
    EXPECT_EQ(99,RomanToArabic("XCIX"));
    EXPECT_EQ(78,RomanToArabic("LXXVIII"));
}


TEST_F(RomanToArabicConvertionTest, CorrectConversionFromRomanToArabicForNumbersLessThan4000){
    EXPECT_EQ(400,RomanToArabic("CD"));
    EXPECT_EQ(1823,RomanToArabic("MDCCCXXIII"));
    EXPECT_EQ(3999,RomanToArabic("MMMCMXCIX"));
}

