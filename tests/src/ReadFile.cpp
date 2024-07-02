#include "ReadFile.h"

#include "FileFolder.hpp"
#include "GtestWrapper.hpp"
#include "StringEquals.h"

TEST(ReadFileC, readBinaryFile)
{
    char bin[100];
    readBinaryFile(bin, (file_folder + "ReadFile.bin").c_str());
    EXPECT_EQ(0, memcmp("123", bin, 3));
}

TEST(ReadFileC, readTextFile)
{
    char txt[100];
    readTextFile(txt, (file_folder + "ReadFile.txt").c_str());
    EXPECT_TRUE(equals("ala\nma kota", txt));
}
