//
// Created by shan on 2022/11/17.
//

#ifndef LAB4_EXECUTOR_H
#define LAB4_EXECUTOR_H

#include "Input.h"
#include "rand.h"
#include "output.h"
#include <string>
using namespace std;

enum type {
    Int, Char, String
};

struct eg {
    type t;
    int a, b;

    string generate();

    eg(type t, int a, int b) : t(t), a(a), b(b) {};
};


class exeUnit {
    string f0, f1;
    Input *input;
    bool test();//执行一次随机tst 返回结果是否一样
public:
    exeUnit(const string &f0, const string &f1, Input *input);
    bool manyTst(); //  多次执行指令判断
};

//对于一个文件夹执行测试
class executor {
    Input *input;
    vector<string> ls;
    vector<eg> egList;
    string tstfile;
    output o;
public:
    void makeList();//初始化eglist
    string makeTst();//生成测试用例内容
    void refreshTst();//刷新测试文件内容
    void testAll();
    explicit executor(Input *input);
};

void execute(string f);
#endif //LAB4_EXECUTOR_H
