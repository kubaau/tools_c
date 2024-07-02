#include "GtestWrapper.hpp"
#include "StringToInt.h"

TEST(StringToIntC, toInt_char)
{
    EXPECT_EQ(0, ctoi('0'));
    EXPECT_EQ(1, ctoi('1'));
    EXPECT_EQ(2, ctoi('2'));
    EXPECT_EQ(3, ctoi('3'));
    EXPECT_EQ(4, ctoi('4'));
    EXPECT_EQ(5, ctoi('5'));
    EXPECT_EQ(6, ctoi('6'));
    EXPECT_EQ(7, ctoi('7'));
    EXPECT_EQ(8, ctoi('8'));
    EXPECT_EQ(9, ctoi('9'));
}

TEST(StringToIntC, toInt_string)
{
    EXPECT_EQ(0, stoi("0"));
    EXPECT_EQ(1, stoi("1"));
    EXPECT_EQ(11, stoi("11"));
    EXPECT_EQ(234, stoi("234"));
    EXPECT_EQ(-1, stoi("-1"));
    EXPECT_EQ(-11, stoi("-11"));
    EXPECT_EQ(-234, stoi("-234"));
}
TEST(StringToIntC, toVectorOfDigits)
{
    u8 digits[3];
    toVectorOfDigits(digits, "0");
    EXPECT_EQ(0, digits[0]);
    toVectorOfDigits(digits, "1");
    EXPECT_EQ(1, digits[0]);
    toVectorOfDigits(digits, "11");
    EXPECT_EQ(1, digits[0]);
    EXPECT_EQ(1, digits[1]);
    toVectorOfDigits(digits, "234");
    EXPECT_EQ(2, digits[0]);
    EXPECT_EQ(3, digits[1]);
    EXPECT_EQ(4, digits[2]);
}

TEST(StringToIntC, wordToByte)
{
    EXPECT_EQ(0, wordToByte("0"));
    EXPECT_EQ(0, wordToByte("00"));
    EXPECT_EQ(1, wordToByte("1"));
    EXPECT_EQ(1, wordToByte("01"));
    EXPECT_EQ(0xCE, wordToByte("CE"));
}

TEST(StringToIntC, hexStringToBytes)
{
    u8 bytes[5];
    EXPECT_EQ(0u, hexStringToBytes(bytes, ""));
    EXPECT_EQ(1u, hexStringToBytes(bytes, "0"));
    EXPECT_EQ(0, bytes[0]);
    EXPECT_EQ(1u, hexStringToBytes(bytes, "00"));
    EXPECT_EQ(0, bytes[0]);
    EXPECT_EQ(1u, hexStringToBytes(bytes, "1"));
    EXPECT_EQ(1, bytes[0]);
    EXPECT_EQ(1u, hexStringToBytes(bytes, "01"));
    EXPECT_EQ(1, bytes[0]);
    EXPECT_EQ(2u, hexStringToBytes(bytes, "00 01"));
    EXPECT_EQ(0, bytes[0]);
    EXPECT_EQ(1, bytes[1]);
    EXPECT_EQ(2u, hexStringToBytes(bytes, "0A CE"));
    EXPECT_EQ(0x0A, bytes[0]);
    EXPECT_EQ(0xCE, bytes[1]);
    EXPECT_EQ(5u, hexStringToBytes(bytes, "00 01 1A B2 3C"));
    EXPECT_EQ(0x00, bytes[0]);
    EXPECT_EQ(0x01, bytes[1]);
    EXPECT_EQ(0x1A, bytes[2]);
    EXPECT_EQ(0xB2, bytes[3]);
    EXPECT_EQ(0x3C, bytes[4]);
}
