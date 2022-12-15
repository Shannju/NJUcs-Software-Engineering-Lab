```
//
// Created by shan on 2022/12/14.
//
#include <unistd.h>
#include <stdlib.h>
#include "gtest/gtest.h"
#include "rand.h"

using namespace std;

TEST(RandTest, RandIntTest) {
    // 测试randInt函数是否在指定范围内返回随机整数
    int a = 1;
    int b = 3;
    for (int i = 0; i < 100; i++) {
        int result = atoi(randInt(a, b).c_str());
        EXPECT_GE(result, a);  // 断言result >= a
        EXPECT_LE(result, b);  // 断言result <= b
    }
}

TEST(RandTest, RandCharTest) {
    // 测试函数能否返回一个字母
    char c=randChar();
    EXPECT_TRUE((c >= 'a' && c<= 'z')||(c >= 'A' && c <= 'Z'));

    // 测试函数能否在不同的调用中返回不同的值
//    EXPECT_NE(randChar(), randChar());
}



TEST(randStringTest, testCase1) { // 测试在区间[1, 10]中随机生成字符串的长度
    for (int i = 0; i < 100; i++) {
        string str = randString(1, 10);
        int len = str.length();
        EXPECT_TRUE(len >= 1 && len <= 10);
    }
}

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
    ASSERT_EQ(filenames.size(), 8);
    EXPECT_EQ(filenames[0], "../gtest_demo/filepath/file1.txt");
    EXPECT_EQ(filenames[1], "../gtest_demo/filepath/subfolder");
    EXPECT_EQ(filenames[2], "../gtest_demo/filepath/.DS_Store");
    EXPECT_EQ(filenames[3], "../gtest_demo/filepath/file2.png");
    EXPECT_EQ(filenames[4], "../gtest_demo/filepath/file4.docx");
    EXPECT_EQ(filenames[5], "../gtest_demo/filepath/file6.pdf");
}

// Test the GetFileNames function with a valid path and subdirectories
TEST(GetFileNamesTest, SubdirectoriesTest) {
    std::string path = "../gtest_demo/filepath";
    std::vector<std::string> filenames;

    // Call the function under test
    GetFileNames(path, filenames);

    // Use gtest assertions to verify the function's behavior
    ASSERT_EQ(filenames.size(), 8);
    EXPECT_EQ(filenames[0], "../gtest_demo/filepath/file1.txt");
    EXPECT_EQ(filenames[1], "../gtest_demo/filepath/subfolder");
    EXPECT_EQ(filenames[2], "../gtest_demo/filepath/.DS_Store");
    EXPECT_EQ(filenames[3], "../gtest_demo/filepath/file2.png");
    EXPECT_EQ(filenames[4], "../gtest_demo/filepath/file4.docx");
    EXPECT_EQ(filenames[5], "../gtest_demo/filepath/file6.pdf");
//    EXPECT_EQ(filenames[6], "/path/to/folder/subfolder");
}

TEST(TestInputFolder, TestConstructor) {
    // 测试InputFolder类的构造函数
    InputFolder folder("../gtest_demo/folderpath");
//    EXPECT_EQ(folder.getFolderPath(), "test_folder");
    EXPECT_EQ(folder.ls.size(), 2); // 假设test_folder目录下有3个子文件夹
}

TEST(TestInputFolder, TestClean) {
    // 测试InputFolder类的clean()函数
    InputFolder folder("../gtest_demo/folderpath");
    folder.clean();
    // 假设test_folder目录下有10个文件，clean()函数能够正确删除8个文件
    EXPECT_EQ(folder.ls.size(), 2);
}

TEST(TestInput, TestConstructor) {
    // 测试Input类的构造函数
    Input input("../gtest_demo/folderpath");
    EXPECT_EQ(input.getFolderPath(), "../gtest_demo/folderpath");
    EXPECT_EQ(input.filenames.size(), 3); // 假设test_input目录下有3个文件
    EXPECT_EQ(input.getFormat(), "../gtest_demo/folderpath/stdin_format.txt");
}

TEST(TestInput, TestFormat) {
    // 测试Input类的format属性
    Input input("../gtest_demo/folderpath");
    EXPECT_EQ(input.getFormat(), "../gtest_demo/folderpath/stdin_format.txt");
}

#include "output.h"

TEST(TestOutput, TestConstructor) {
    // 测试output类的构造函数
    output out;
    out.init();
    // 假设equal.csv、inequal.csv和abnormal.csv文件创建成功
    EXPECT_TRUE(out.equal.is_open());
    EXPECT_TRUE(out.inequal.is_open());
    EXPECT_TRUE(out.abnormal.is_open());
}

TEST(TestOutput, TestAdd) {
    // 测试output类的add()函数
    output out;
    out.init();
    out.add(true, "file1", "file2");
    out.add(false, "file3", "file4");
    // 假设add()函数能够正确地将数据写入equal.csv和inequal.csv文件中
    std::ifstream equal("../output/equal.csv");
    std::string line;
    std::getline(equal, line);
    EXPECT_EQ(line, "file1,file2");
    std::getline(equal, line);
    EXPECT_EQ(line, "/input/50A/33794240.cpp,/input/50A/29019948.cpp");
    equal.close();
    std::ifstream inequal("../output/inequal.csv");
    std::getline(inequal, line);
    EXPECT_EQ(line, "file1,file2");
    std::getline(inequal, line);
    EXPECT_EQ(line, "/input/50A/29019948.cpp,/input/50A/30534178.cpp");
    inequal.close();
}
TEST(TestOutput, TestAddAb) {
    // 测试output类的addAb()函数
    output out;
    out.init();
    out.addAb("file1");
    out.addAb("file2");
    out.addAb("file2");
    // 确保addAb()函数能够正确地将异常文件名添加到abnormalList中
    EXPECT_EQ(out.abnormalList.size(), 2);
    EXPECT_EQ(out.abnormalList[0], "file1");
    EXPECT_EQ(out.abnormalList[1], "file2");
}


#include "gtest/gtest.h"
#include "executor.h"

TEST(TestExecutor, TestMakeList) {
    // 测试executor类的makeList()函数
    Input input("/Users/shan/Desktop/Software-Engineering/NJUcs-Software-Engineering-Lab/lab4/data");
    output out;
    out.init();
    executor exe(&input, &out);
    exe.makeList();
    // 假设格式文件中包含int(a,b)、char和string(c,d)三个关键字
    // 则egList应该包含3个eg对象，分别是Int类型、Char类型和String类型
    EXPECT_EQ(exe.egList.size(), 3);
    EXPECT_EQ(exe.egList[0].t, Int);
    EXPECT_EQ(exe.egList[1].t, Char);
    EXPECT_EQ(exe.egList[2].t, String);
}

TEST(TestExecutor, TestMakeTst) {
    // 测试executor类的makeTst()函数
    Input input("/Users/shan/Desktop/Software-Engineering/NJUcs-Software-Engineering-Lab/lab4/data");
    output out;
    out.init();
    executor exe(&input, &out);
    exe.makeList();
    std::string tst = exe.makeTst();
    // 假设格式文件中包含int(a,b)、char和string(c,d)三个关键字
    // 则makeTst()应该返回一个由随机生成的整数、字符和字符串组成的字符串
    // 可以通过检查返回值的格式来验证函数的正确性
    EXPECT_EQ(tst.substr(0, tst.find(' ')), randInt(1, 2));
//    EXPECT_EQ(tst.substr(tst.find(' ')+1, tst.find(' ', tst.find(' ')+1)), randChar());
    EXPECT_EQ(tst.substr(tst.find(' ', tst.find(' ')+1)+1), randString(1, 2));
}
TEST(TestExecutor, TestTestAll) {
    // 测试executor类的testAll()函数
    Input input("/Users/shan/Desktop/Software-Engineering/NJUcs-Software-Engineering-Lab/lab4/data");
    output out;
    out.init();
    executor exe(&input, &out);
    exe.testAll();
    // testAll()函数会依次测试所有的文件对，并将结果写入output对象
    // 因此可以通过检查output对象中记录的结果来验证testAll()函数的正确性
//    std::vector<std::pair<std::string, std::string>> equals = out.getEqualList();
//    std::vector<std::pair<std::string, std::string>> inequals = out.getInequalList();
}

TEST(TestExecutor, TestTest) {
    // 测试executor类的test()函数
    Input input("/Users/shan/Desktop/Software-Engineering/NJUcs-Software-Engineering-Lab/lab4/data");
    output out;
    out.init();
    executor exe(&input, &out);
    exe.makeList();
    // 首先需要调用makeList()函数来生成输入格式列表
    exeUnit unit("file1.cpp", "file2.cpp", &input, &out);
    // 然后创建一个exeUnit对象
    // 指定要测试的两个文件
    bool result = exe.manyTst(unit,2);
    // 调用test()函数，返回测试结果
    // 可以通过检查返回值来验证函数的正确性
    EXPECT_TRUE(result);
}

//TEST(IntegrationTest, TestALL)

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

