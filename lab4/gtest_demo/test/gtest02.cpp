//
// Created by shan on 2022/12/14.
//
#include <unistd.h>
#include <stdlib.h>
#include "gtest/gtest.h"
#include "Input.h"

using namespace std;
// Test the GetFileNames function
TEST(GetFileNamesTest, BasicTest) {
    std::string path = "../gtest_demo/filepath";
    std::vector<std::string> filenames;

    // Call the function under test
    GetFileNames(path, filenames);

    // Use gtest assertions to verify the function's behavior
    ASSERT_TRUE(filenames.size() > 0);
    EXPECT_EQ(filenames[0], "../gtest_demo/filepath/file1.txt");
}

// Test the GetFileNames function with an invalid path
TEST(GetFileNamesTest, InvalidPathTest) {
    std::string path = "/invalid/path";
    std::vector<std::string> filenames;

    // Call the function under test
    GetFileNames(path, filenames);

    // Use gtest assertions to verify the function's behavior
    ASSERT_TRUE(filenames.empty());
}

// Test the GetFileNames function with a valid path and multiple file types
TEST(GetFileNamesTest, MultipleFileTypesTest) {
    std::string path = "../gtest_demo/filepath";
    std::vector<std::string> filenames;

    // Call the function under test
    GetFileNames(path, filenames);

    // Use gtest assertions to verify the function's behavior
    ASSERT_EQ(filenames.size(), 6);
    EXPECT_EQ(filenames[0], "../gtest_demo/filepath/file1.txt");
    EXPECT_EQ(filenames[1], "../gtest_demo/filepath/file2.png");
    EXPECT_EQ(filenames[2], "../gtest_demo/filepath/file3.mp4");
    EXPECT_EQ(filenames[3], "../gtest_demo/filepath/file4.docx");
    EXPECT_EQ(filenames[4], "../gtest_demo/filepath/file5.xlsx");
    EXPECT_EQ(filenames[5], "../gtest_demo/filepath/file6.pdf");
}

// Test the GetFileNames function with a valid path and subdirectories
TEST(GetFileNamesTest, SubdirectoriesTest) {
    std::string path = "../gtest_demo/filepath";
    std::vector<std::string> filenames;

    // Call the function under test
    GetFileNames(path, filenames);

    // Use gtest assertions to verify the function's behavior
    ASSERT_EQ(filenames.size(), 12);
    EXPECT_EQ(filenames[0], "../gtest_demo/filepath/file1.txt");
    EXPECT_EQ(filenames[1], "../gtest_demo/filepath/file2.png");
    EXPECT_EQ(filenames[2], "../gtest_demo/filepath/file3.mp4");
    EXPECT_EQ(filenames[3], "../gtest_demo/filepath/file4.docx");
    EXPECT_EQ(filenames[4], "../gtest_demo/filepath/file5.xlsx");
    EXPECT_EQ(filenames[5], "../gtest_demo/filepath/file6.pdf");
//    EXPECT_EQ(filenames[6], "/path/to/folder/subfolder");
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}