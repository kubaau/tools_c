#include "FileCommon.h"

#include "FileFolder.hpp"
#include "GtestWrapper.hpp"

TEST(FileCommonC, open_and_jump)
{
    auto file = openFile((file_folder + "ReadFile.bin").c_str(), "r");

    jumpToEnd(file);
    fgetc(file);
    EXPECT_TRUE(feof(file));

    jumpToStart(file);
    EXPECT_EQ('1', fgetc(file));

    jump(file, SEEK_SET);
    EXPECT_EQ('1', fgetc(file));

    fseek(file, 0, SEEK_CUR);
    EXPECT_EQ('2', fgetc(file));

    fclose(file);
}
