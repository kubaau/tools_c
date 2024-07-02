#include "WriteFile.h"

#include "GtestWrapper.hpp"
#include "ReadFile.h"
#include "StringEquals.h"

TEST(WriteFileC, writeBinaryFile)
{
    char bin[] = {'1', '2', '3'};
    const char* path = "WriteFile.bin";
    writeBinaryFile(path, bin, sizeof(bin));
    readBinaryFile(bin, "WriteFile.bin");
    EXPECT_EQ(0, memcmp("123", bin, 3));
}

TEST(WriteFileC, writeTextFile)
{
    const char* text = "ala\nma kota";
    const size_t len = strlen(text);
    const char* path = "WriteFile.txt";
    writeTextFile(path, text, len);

    char txt[100];
    readTextFile(txt, path);
    EXPECT_EQ(0, memcmp(text, txt, len));
}
